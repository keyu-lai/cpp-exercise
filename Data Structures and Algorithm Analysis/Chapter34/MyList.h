#ifndef MY_LIST_H
#define MY_LIST_H

#include <stdexcept>
#include <iostream>

template<typename T>
class MyList
{
private:
	struct Node {
		Node *pre;
		Node *next;
		T content;
		Node(Node *a = nullptr, Node *b = nullptr, const T &t = T()) : pre(a), next(b), content(t) {}
	};

public:
	class const_iterator{
		friend class MyList < T > ;
	public:
		const_iterator() : node(nullptr) {}
		const T& operator*() { 
			assertIsHead(node);
			assertIsTail(node);
			return node->content;
		}
		const_iterator& operator++() {
			assertIsTail(node);
			node = node->next;
			return *this;
		}
		const_iterator operator++(int) {
			assertIsTail(node);
			const_iterator old = *this;
			node = node->next;
			return old;
		}
		const_iterator& operator--() {
			assertIsHead(node);
			node = node->pre;
			return *this;
		}
		const_iterator operator--(int) {
			assertIsHead(node);
			const_iterator old = *this;
			node = node->pre;
			return old;
		}
		bool operator== (const const_iterator &rhs) const 
		{ return node == rhs.node; }
		bool operator!= (const const_iterator &rhs) const 
		{ return node != rhs.node; }

	protected:
		Node *node;
		const_iterator(Node *p) : node(p) {}
		void assertIsHead(Node *p) {
			if (p->pre == nullptr)
				throw runtime_error("iterator out of range!");
		}
		void assertIsTail(Node *p) {
			if (p->next == nullptr)
				throw runtime_error("iterator out of range!");
		}
	};
	class iterator: public const_iterator{
		friend class MyList < T > ;
	public:
		iterator(): const_iterator() {}
		T& operator*() { return node->content; }
		const T& operator*() const { 
			assertIsHead(node);
			assertIsTail(node);
			return node->content; 
		}
		iterator & operator++() {
			assertIsTail(node);
			node = node->next;
			return *this;
		}
		iterator operator++(int) {
			assertIsTail(node);
			iterator old = *this;
			node = node->next;
			return old;
		}
		iterator & operator--() {
			assertIsHead(node);
			node = node->pre;
			return *this;
		}
		iterator operator--(int) {
			assertIsHead(node);
			iterator old = *this;
			node = node->pre;
			return old;
		}
	protected:
		iterator(Node *p) : const_iterator(p) {}
	};

public:
	MyList();
	MyList(const MyList & list);
	~MyList();
	const MyList& operator=(const MyList &list);

	iterator begin() { return iterator(head->next); }
	iterator end() { return iterator(tail); }
	const_iterator begin() const { return const_iterator(head->next); }
	const_iterator end() const { return const_iterator(tail); }

	size_t size() const { return mySize; }
	bool empty() const { return mySize == 0; }
	void clear() {
		while (!empty()) 
			pop_front();
	}
	T& front() { return *begin(); }
	const T& front() const { return *begin(); }
	T& back() { return *(--end()); }
	const T& back() const { return *(--end()); }
	void push_front(const T &t) { insert(begin(), t); }
	void push_back(const T &t) { insert(end(), t); }
	void pop_front() { erase(begin()); }
	void pop_back() { erase(--end()); }

	iterator insert(iterator itr, const T &t);
	iterator erase(iterator itr);
	iterator erase(iterator a, iterator b);
	void splice(const iterator &position, MyList &lst);

private:
	Node *head;
	Node *tail;
	size_t mySize;
	void init();
	void assertIsHead(const const_iterator &p) {
		if (p.node == head)
			throw runtime_error("iterator out of range!");
	}
	void assertIsTail(const const_iterator &p) {
		if (p.node == tail)
			throw runtime_error("iterator out of range!");
	}
};


template<typename T>
MyList<T>::MyList()
{
	init();
}

template<typename T>
MyList<T>::MyList(const MyList & rhs)
{
	init();
	*this = rhs;
}

template<typename T>
MyList<T>::~MyList()
{
	clear();
	delete head;
	delete tail;
}

template<typename T>
const MyList<T>& MyList<T>::operator = (const MyList& rhs)
{
	if (this == &rhs)
		return *this;
	clear();
	for (auto i = rhs.begin(); i != rhs.end(); ++i)
		push_back(*i);
	return *this;
}

template<typename T>
void MyList<T>::init()
{
	mySize = 0;
	head = new Node();
	tail = new Node();
	head->next = tail;
	tail->pre = head;
}

template<typename T>
typename MyList<T>::iterator MyList<T>::insert(iterator itr, const T &t)
{
	assertIsHead(itr);
	Node *p = itr.node;
	++mySize;
	p->pre->next = new Node(p->pre, p, t);
	p->pre = p->pre->next;
	return iterator(p->pre);
}

template<typename T>
typename MyList<T>::iterator MyList<T>::erase(iterator itr)
{
	assertIsHead(itr);
	Node *p = itr.node;
	p->next->pre = p->pre;
	p->pre->next = p->next;
	auto next = iterator(p->next);
		delete p;
	--mySize;
	return iterator(next);
}

template<typename T>
typename MyList<T>::iterator MyList<T>::erase(iterator s, iterator e)
{
	assertIsHead(s);
	for (auto itr = s; itr != e;)
		itr = erase(itr);
	return e;
}

template<typename T>
void MyList<T>::splice(const iterator &position, MyList &lst)
{
	assertIsHead(position);
	if (this != &lst) {
		auto nodePos = position.node;
		nodePos->pre->next = lst.head->next;
		lst.head->next->pre = nodePos->pre;
		nodePos->pre = lst.tail->pre;
		lst.tail->pre->next = nodePos;
		mySize += lst.mySize;
		lst.mySize = 0;
		lst.head->next = lst.tail;
		lst.tail->pre = lst.head;
	}
}

#endif

