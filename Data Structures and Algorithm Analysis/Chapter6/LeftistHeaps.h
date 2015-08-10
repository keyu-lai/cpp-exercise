#ifndef LEFTIST_HEAPS_H
#define LEFTIST_HEAPS_H

#include <iostream>
#include <stdexcept>
#include <vector>
#include <list>

template<typename T>
class LeftistHeaps
{
public:
	LeftistHeaps() : root(nullptr) {}
	LeftistHeaps(const LeftistHeaps &heap);
	~LeftistHeaps() { makeEmpty(); }
	const LeftistHeaps& operator=(const LeftistHeaps &heap);

	bool isEmpty() const;
	const T& findMin() const;
	void insert(const T &t) {
		auto tmp = new LeftistNode(t);
		root = merge(root, tmp);
	}
	void deleteMin();
	void deleteMin(T &t);
	void makeEmpty();
	void merge(LeftistHeaps &heap);
	void print() {
		print(root);
	}

private:
	struct LeftistNode {
		T element;
		LeftistNode *left;
		LeftistNode *right;
		int npl;
		LeftistNode(const T& t, LeftistNode *l = nullptr, LeftistNode *r = nullptr, int len = 0) :
			element(t), left(l), right(r), npl(len) { }
	};
	LeftistNode *root;
	void print(LeftistNode *node) {
		static int i = 0;
		if (node != nullptr) {
			i++;
			auto tmp = i;
			print(node->left);
			std::cout << node->element << "(" << tmp << ")" << std::ends;
			print(node->right);
		}
	}
	LeftistNode* copyNode(LeftistNode *node);
	LeftistNode*& merge(LeftistNode* &l, LeftistNode* &r);
	//void makeEmpty(LeftistNode* node);
	void swapNode(LeftistNode* &n1, LeftistNode* &n2) {
		auto tmp = n1;
		n1 = n2;
		n2 = tmp;
	}
};

template<typename T>
void LeftistHeaps<T>::merge(LeftistHeaps &heap)
{
	std::vector<LeftistNode*> vec;
	auto ptr1 = root, ptr2 = heap.root;
	while (ptr1 != nullptr && ptr2 != nullptr) {
		if (ptr1->element < ptr2->element) {
			vec.push_back(ptr1);
			ptr1 = ptr1->right;
		} else {
			vec.push_back(ptr2);
			ptr2 = ptr2->right;
		}
	}
	ptr1 = (ptr1 != nullptr ? ptr1 : ptr2);
	while (ptr1 != nullptr) {
		vec.push_back(ptr1);
		ptr1 = ptr1->right;
	}
	if (vec.size() > 1) {
		for (auto i = vec.rbegin() + 1; i != vec.rend(); ++i) {
			(*i)->right = *(i - 1);
			if ((*i)->left == nullptr) {
				swapNode((*i)->left, (*i)->right);
				(*i)->npl = 0;
			} else {
				if ((*i)->left->npl < (*i)->right->npl) 
					swapNode((*i)->left, (*i)->right);
				(*i)->npl = (*i)->right->npl + 1;
			}
		}
	}
	if (vec.size() > 0) {
		root = *vec.begin();
		heap.root = nullptr;
	}
}

template<typename T>
typename LeftistHeaps<T>::LeftistNode*& LeftistHeaps<T>::merge(LeftistNode* &l, LeftistNode* &r)
{
	if (l == nullptr)
		return r;
	if (r == nullptr)
		return l;
	if (l->element < r->element) {
		if (l->left == nullptr)
			l->left = r;
		else {
			l->right = merge(l->right, r);
			if (l->left->npl < l->right->npl)
				swapNode(l->left, l->right);
			l->npl = l->right->npl + 1;
		}
		return l;
	} else {
		if (r->left == nullptr)
			r->left = l;
		else {
			r->right = merge(l, r->right);
			if (r->left->npl < r->right->npl)
				swapNode(r->left, r->right);
			r->npl = r->right->npl + 1;
		}
		return r;
	}
}

//template<typename T>
//void LeftistHeaps<T>::merge(LeftistHeaps &heap)
//{
//	if (this == &heap)
//		return;
//	root = merge(root, heap.root);
//	heap.root = nullptr;
//}

template<typename T>
typename LeftistHeaps<T>::LeftistNode* LeftistHeaps<T>::copyNode(LeftistNode* node)
{
	if (node == nullptr)
		return nullptr;
	return new LeftistNode(node->element, copyNode(node->left), copyNode(node->right));
}

template<typename T>
LeftistHeaps<T>::LeftistHeaps(const LeftistHeaps &heap)
{
	root = copyNode(heap.root);
}

template<typename T>
const LeftistHeaps<T>& LeftistHeaps<T>::operator=(const LeftistHeaps &heap)
{
	if (this != &heap) {
		makeEmpty();
		root = copyNode(heap.root);
	}
	return *this;
}

template<typename T>
bool LeftistHeaps<T>::isEmpty() const
{
	return root == nullptr;
}

template<typename T>
const T& LeftistHeaps<T>::findMin() const
{
	if (isEmpty())
		throw runtime_error("no element in the heap!");
	return root->element;
}

template<typename T>
void LeftistHeaps<T>::deleteMin()
{
	if (isEmpty())
		throw runtime_error("no element in the heap!");
	auto tmp = root;
	root = merge(root->left, root->right);
	delete tmp;
}

template<typename T>
void LeftistHeaps<T>::deleteMin(T& t)
{
	t = findMin();
	deleteMin();
}

//template<typename T>
//void LeftistHeaps<T>::makeEmpty()
//{
//	makeEmpty(root);
//	root = nullptr;
//}

template<typename T>
void LeftistHeaps<T>::makeEmpty()
{
	std::list<LeftistNode*> l;
	if (root != nullptr) {
		l.push_back(root);
		while (l.size() != 0) {
			auto tmp = l.front();
			if (tmp->left != nullptr)
				l.push_back(tmp->left);
			if (tmp->right != nullptr)
				l.push_back(tmp->right);
			l.pop_front();
			delete tmp;
		}
		root = nullptr;
	}
}

//template<typename T>
//void LeftistHeaps<T>::makeEmpty(LeftistNode* node)
//{
//	if (node != nullptr) {
//		makeEmpty(node->left);
//		makeEmpty(node->right);
//		delete node;
//	}
//}

#endif