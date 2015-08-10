#include "myList.h"


template<typename T>
class MyList
{
public:
	MyList();
	//MyList(MyList & list);
	~MyList(){}

};


using namespace std;

template<typename T>
MyList<T>::MyList()
{
	//init();
}

template<typename T>
MyList<T>::MyList(MyList & list)
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
	for (auto i = rhs.begin(); i != ths.end(); ++i)
		push_back(*i);
	return *this;
}

template<typename T>
void MyList<T>::init()
{
	Mysize = 0;
	head = new Node();
	tail = new Node();
	head->next = tail;
	tail->pre = head;
}

template<typename T>
MyList<T>::iterator MyList<T>::insert(iterator itr, const T &t)
{
	Node *p = itr.node;
	++mySize;
	p->pre->next = new Node(p->pre, p, t);
	p->pre = p->pre->next;
	return iterator(p->pre);
}

template<typename T>
MyList<T>::iterator MyList<T>::erase(iterator itr)
{
	Node *p = iter.node;
	p->next->pre = p->pre;
	p->pre->next = p->next;
	auto next = iterator(p->next)
	delete p;
	--mySize;
	return iterator(next);
}

template<typename T>
MyList<T>::iterator MyList<T>::erase(iterator a, iterator b)
{
	a->pre->next = b;
	b->pre = a->pre;
	for (auto i = a; i != b;) {
		i = i->next;
		delete i->pre;
		--mySize;
	}
	return iterator(b);
}




