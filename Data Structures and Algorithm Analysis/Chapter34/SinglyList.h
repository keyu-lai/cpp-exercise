/*  3.11 - 3.12  */

#ifndef SINLY_LIST_H
#define SINLY_LIST_H

template<typename T>
class SinlyList
{
private:
	struct Node {
		Node *next;
		T content;
		Node(Node *a = nullptr, const T &t = T()) :next(a), content(t) { }
	};
public:
	SinlyList() : head(new Node()), theSize(0) { }
	~SinlyList() {
		auto p = head->next;
		delete head;
		while (theSize) {
			auto tmp = p;
			p = p->next;
			delete tmp;
			--theSize;
		}
	}
	size_t size() { return theSize; }
	void print() {
		auto count = theSize;
		auto p = head->next;
		while (count) {
			cout << p->content << ends;
			p = p->next;
			--count;
		}
	}
	bool contain(const T &t) const {
		auto ptr = head;
		while (ptr->next != nullptr) {
			if ((ptr = ptr->next)->content == t)
				return true;
		}
		return false;
	}
	//bool add(const T &t) {
	//	auto ptr = head;
	//	while (ptr->next != nullptr) {
	//		if ((ptr = ptr->next)->content == t)
	//			return false;
	//	}
	//	ptr->next = new Node(nullptr, t);
	//	++theSize;
	//	return true;
	//}
	bool add(const T &t) {
		auto ptr = head;
		while (ptr->next != nullptr) {
			if (ptr->next->content == t)
				return false;
			else if (ptr->next->content < t)
				ptr = ptr->next;
			else {
				ptr->next = new Node(ptr->next, t);
				++theSize;
				return true;
			}
		}
		ptr->next = new Node(nullptr, t);
		++theSize;
		return true;
	}
	bool remove(const T &t) {
		auto ptr = head;
		while (ptr->next != nullptr) {
			if (ptr->next->content == t) {
				auto tmp = ptr->next;
				ptr->next = tmp->next;
				delete tmp;
				--theSize;
				return true;
			} else
				ptr = ptr->next;
		}
		return false;
	}
private:
	Node *head;
	size_t theSize;
};

#endif