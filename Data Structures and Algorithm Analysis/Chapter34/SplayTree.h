#ifndef SPLAY_TREE
#define SPLAY_TREE

#include <vector>

template<typename T>
class SplayTree
{
public:
	SplayTree(): root(nullptr) {}
	~SplayTree() { makeEmpty(); }
	SplayTree(const SplayTree& b);
	SplayTree& operator=(const SplayTree &t);
	
	const T& findMin() const;
	const T& findMax() const;
	bool contains(const T &t);
	bool isEmpty() const;
	void printTree() const;

	void makeEmpty();
	void insert(const T &t);
	void remove(const T &t);
	T findKth(const size_t &k) const;
	const T& top() { return root->element; }
private:
	struct SplayNode {
		T element;
		SplayNode* left;
		SplayNode* right;
		SplayNode(const T& t, SplayNode* l = nullptr, SplayNode* r = nullptr) : element(t), left(l), right(r) {}
	};
	void findKth(SplayNode* node, const size_t &k, size_t &count, T& t) const;
	void singleLeft(SplayNode* &node);
	void singleRight(SplayNode* &node);
	void doubleLeft(SplayNode* &node);
	void doubleRight(SplayNode* &node);
	void zigLeft(SplayNode* &node);
	void zigRight(SplayNode* &node);
	void remove(const T &t, SplayNode* &node);
	void insert(SplayNode* &node, const T &t);
	void copyNode(const SplayNode *from, SplayNode* &to);
	void makeEmpty(SplayNode* &node);
	void printNode(const SplayNode* node) const;
	SplayNode *root;
};

template<typename T>
void SplayTree<T>::findKth(SplayNode* node, const size_t &k, size_t &count, T& t) const
{
	if (node != nullptr && count < k) {
		findKth(node->left, k, count, t);
		++count;
		if (count == k)
			t = node->element;
		findKth(node->right, k, count, t);
	}
}

template<typename T>
T SplayTree<T>::findKth(const size_t &k) const
{
	size_t count = 0;
	T t;
	findKth(root, k, count, t);
	if (count >= k)
		return t;
	else 
		runtime_error("Overflow");
}

template<typename T>
const T& SplayTree<T>::findMin() const
{
	if (isEmpty())
		throw runtime_error("Try to use an empty tree!");
	auto node = root;
	else {
		while (node->left != nullptr)
			node = node->left;
		return node->element;
	}
}

template<typename T>
const T& SplayTree<T>::findMax() const
{
	if (isEmpty())
		throw runtime_error("Try to use an empty tree!");
	else {
		auto node = root;
		while (node->right != nullptr)
			node = node->right;
		return node->element;
	}
}

template<typename T>
void SplayTree<T>::singleRight(SplayNode* &node)
{
	auto tmp = node->right->left;
	node->right->left = node;
	node = node->right;
	node->left->right = tmp;
}

template<typename T>
void  SplayTree<T>::singleLeft(SplayNode* &node)
{
	auto tmp = node->left->right;
	node->left->right = node;
	node = node->left;
	node->right->left = tmp;
}

template<typename T>
void  SplayTree<T>::doubleRight(SplayNode* &k1)
{
	auto k3 = k1->right, k2 = k3->left;
	auto tmp = k2->right;
	k2->right = k3;
	k3->left = tmp;
	tmp = k2->left;
	k2->left = k1;
	k1->right = tmp;
	k1 = k2;
}

template<typename T>
void  SplayTree<T>::doubleLeft(SplayNode* &k3)
{
	auto  k1 = k3->left, k2 = k1->right;
	auto tmp = k2->left;
	k2->left = k1;
	k1->left = tmp;
	tmp = k2->right;
	k2->right = k3;
	k3->left = tmp;
	k3 = k2;
}

template<typename T>
void  SplayTree<T>::zigLeft(SplayNode* &G)
{
	auto P = G->left, X = P->left;
	G->left = P->right;
	P->right = G;
	P->left = X->right;
	X->right = P;
	G = X;
}

template<typename T>
void  SplayTree<T>::zigRight(SplayNode* &X)
{
	auto P = X->right, G = P->right;
	X->right = P->left;
	P->left = X;
	P->right = G->left;
	G->left = P;
	X = G;
}

template<typename T>
bool SplayTree<T>::contains(const T &t) 
{
	vector<SplayNode**> l;
	if (isEmpty())
		return false;
	else {
		SplayNode** node = &root;
		while (*node != nullptr) {
			l.push_back(node);
			if ((*node)->element == t) {
				while (true) {
					if (l.size() == 1)
						return true;
					else if (l.size() == 2) {
						if ((**(l.end() - 1))->element < (**(l.end() - 2))->element)
							singleLeft(**(l.end() - 2));
						else
							singleRight(**(l.end() - 2));
						return true;
					}
					else {
						SplayNode* &a = **(l.end() - 1);
						SplayNode* &b = **(l.end() - 2);
						SplayNode* &c = **(l.end() - 3);
						if (c->element > b->element && b->element > a->element)
							zigLeft(c);
						else if (c->element > b->element && b->element < a->element)
							doubleLeft(c);
						else if (c->element < b->element && b->element < a->element) {
							zigRight(c);
						}
						else
							doubleRight(c);
						l.pop_back();
						l.pop_back();
					}
				}
			} else if ((*node)->element < t)
				node = &((*node)->right);
			else
				node = &((*node)->left);
		}
		return false;
	}
}

template<typename T>
bool SplayTree<T>::isEmpty() const
{
	return root == nullptr;
}

template<typename T>
void SplayTree<T>::printNode(const SplayNode* node) const
{
	if (node != nullptr) {
		printNode(node->left);
		cout << node->element << ends;
		printNode(node->right);
	}
}

template<typename T>
void SplayTree<T>::printTree() const
{
	printNode(root);
}

template<typename T>
void SplayTree<T>::makeEmpty(SplayNode* &node)
{
	if (node != nullptr) {
		makeEmpty(node->left);
		makeEmpty(node->right);
		delete node;
		node = nullptr;
	}
}

template<typename T>
void SplayTree<T>::makeEmpty()
{
	makeEmpty(root);
}

template<typename T>
void SplayTree<T>::insert(SplayNode* &node, const T &t)
{
	if (node == nullptr) 
		node = new SplayNode(t);
	else if (node->element == t)
		;
	else if (node->element < t) 
		insert(node->right, t);
	else
		insert(node->left, t);
}

template<typename T>
void SplayTree<T>::insert(const T &t)
{
	insert(root, t);
}

template<typename T>
void SplayTree<T>::remove(const T &t, SplayNode* &node)
{
	if (node == nullptr)
		return;
	else if (t < node->element)
		remove(t, node->left);
	else if (node->element < t)
		remove(t, node->right);
	else if (node->left != nullptr && node->right != nullptr) {
		SplayNode* *tmp = &node->right;
		while ((*tmp)->left != nullptr)
			*tmp = (*tmp)->left;
		node->element = (*tmp)->element;
		remove(node->element, *tmp);
	}
	else {
		auto old = node;
		node = (node->left != nullptr) ? node->left : node->right;
		delete old;
	}
}

template<typename T>
void SplayTree<T>::remove(const T &t)
{
	remove(t, root);
}

template<typename T>
SplayTree<T>::SplayTree(const SplayTree& b) : root(nullptr)
{
	*this = b;
}

template<typename T>
void SplayTree<T>::copyNode(const SplayNode *from, SplayNode* &to)
{
	if (from != nullptr) {
		to = new SplayNode(from->element);
		copyNode(from->left, to->left);
		copyNode(from->right, to->right);
	}
}

template<typename T>
SplayTree<T>& SplayTree<T>::operator=(const SplayTree &t)
{
	if (this != &t) {
		makeEmpty();
		copyNode(t.root, root);
	}
	return *this;
}

#endif