#ifndef AVL_TREE
#define AVL_TREE

#include<vector>
#include <cmath>

template<typename T>
class AVLTree
{
public:
	AVLTree(): root(nullptr) {}
	~AVLTree() { makeEmpty(); }
	AVLTree(const AVLTree& b);
	AVLTree& operator=(const AVLTree &t);
	
	const T& findMin() const;
	const T& findMax() const;
	bool contains(const T &t) const;
	bool isEmpty() const;
	void printTree() const;

	void makeEmpty();
	bool check() const;
	void insert(const T &t);
	void remove(const T &t);
private:
	struct AVLNode {
		T element;
		AVLNode* left;
		AVLNode* right;
		int height;
		AVLNode(const T& t, AVLNode* l = nullptr, AVLNode* r = nullptr, int h = 0) : element(t), left(l), right(r), height(h) {}
	};
	void renewHeight(AVLNode* &node) const { node->height = max(height(node->left), height(node->right)) + 1; }
	const int max(const int a,const int b) const { return a > b ? a : b; }
	bool check(AVLNode* const &node) const;
	T* deleteMin(AVLNode* &node);
	int height(AVLNode *t) const { return t == nullptr ? -1 : t->height; }
	void singleRight(AVLNode* &node);
	void singleLeft(AVLNode* &node);
	void doubleRight(AVLNode* &node);
	void doubleLeft(AVLNode* &node);
	void remove(const T &t, AVLNode* &node);
	void insert(AVLNode* &node, const T &t);
	void copyNode(const AVLNode *from, AVLNode* &to);
	void makeEmpty(const AVLNode* node);
	void printNode(const AVLNode* node) const;
	AVLNode *root;
};

template<typename T>
bool AVLTree<T>::check() const
{
	return check(root);
}

template<typename T>
bool AVLTree<T>::check(AVLNode* const &node) const
{
	bool thisNode = false;
	if (abs(height(node->left) - height(node->right)) < 2 && height(node) == max(height(node->left), height(node->right)) + 1)
		thisNode = true;
	return thisNode && (node->left ? check(node->left) : true) && (node->right ? check(node->right) : true);
}


template<typename T>
const T& AVLTree<T>::findMin() const
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
const T& AVLTree<T>::findMax() const
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
bool AVLTree<T>::contains(const T &t) const
{
	if (isEmpty())
		return false;
	else {
		auto node = root;
		while (node != nullptr) {
			if (node->element == t)
				return true;
			else if (node->element < t)
				node = node->right;
			else
				node = node->left;
		}
		return false;
	}
}

template<typename T>
bool AVLTree<T>::isEmpty() const
{
	return root == nullptr;
}

template<typename T>
void AVLTree<T>::printNode(const AVLNode* node) const
{
	if (node != nullptr) {
		printNode(node->left);
		cout << node->element << ends;
		printNode(node->right);
	}
}

template<typename T>
void AVLTree<T>::printTree() const
{
	printNode(root);
}

template<typename T>
void AVLTree<T>::makeEmpty(const AVLNode* node)
{
	if (node != nullptr) {
		makeEmpty(node->left);
		makeEmpty(node->right);
		delete node;
		node = nullptr;
	}
}

template<typename T>
void AVLTree<T>::makeEmpty()
{
	makeEmpty(root);
}

template<typename T>
void AVLTree<T>::singleRight(AVLNode* &node)
{
	auto tmp = node->right->left;
	node->right->left = node;
	node = node->right;
	node->left->right = tmp;
	node->left->height = max(height(node->left->left), height(node->left->right)) + 1;
	node->height = max(height(node->left), height(node->right)) + 1;
}

template<typename T>
void  AVLTree<T>::singleLeft(AVLNode* &node)
{
	auto tmp = node->left->right;
	node->left->right = node;
	node = node->left;
	node->right->left = tmp;
	node->right->height = max(height(node->right->left), height(node->right->right)) + 1;
	node->height = max(height(node->left), height(node->right)) + 1;
}

template<typename T>
void  AVLTree<T>::doubleRight(AVLNode* &k1)
{
	auto k3 = k1->right, k2 = k3->left;
	auto tmp = k2->right;
	k2->right = k3;
	k3->left = tmp;
	tmp = k2->left;
	k2->left = k1;
	k1->right = tmp;
	k1 = k2;
	renewHeight(k1->left);
	renewHeight(k1->right);
	renewHeight(k1);
}

template<typename T>
void  AVLTree<T>::doubleLeft(AVLNode* &k3)
{
	auto  k1 = k3->left, k2 = k1->right;
	auto tmp = k2->left;
	k2->left = k1;
	k1->left = tmp;
	tmp = k2->right;
	k2->right = k3;
	k3->left = tmp;
	k3 = k2;
	renewHeight(k3->left);
	renewHeight(k3->right);
	renewHeight(k3);
}

//template<typename T>
//void AVLTree<T>::insert(AVLNode* &node, const T &t)
//{
//	if (node == nullptr) 
//		node = new AVLNode(t);
//	else if (node->element == t)
//		return;
//	else if (node->element < t) {
//		insert(node->right, t);
//		if (height(node->right) - height(node->left) == 2) {
//			if (t > node->right->element)
//				singleRight(node);
//			else
//				doubleRight(node);
//		}
//	}
//	else {
//		insert(node->left, t);
//		if (height(node->left) - height(node->right) == 2) {
//			if (t < node->left->element)
//				singleLeft(node);
//			else
//				doubleLeft(node);
//		}
//	}
//	node->height = max(height(node->left), height(node->right)) + 1;
//}


template<typename T>
void AVLTree<T>::insert(AVLNode* &node, const T &t)
{
	vector<AVLNode**> vec;
	AVLNode* *tmp = &node;
	while (true) {
		if (*tmp != nullptr) {
			vec.push_back(tmp);
			if ((*tmp)->element == t)
				return;
			if ((*tmp)->element > t)
				tmp = &((*tmp)->left);
			else
				tmp = &((*tmp)->right);
		}
		else 
			break;
	}
	vec.push_back(tmp);
	*tmp = new AVLNode(t);
	if (tmp != &root)
		renewHeight(**(vec.end() - 2));
	if (vec.size() > 2) {
		auto i = vec.end() - 2;
		int j = 0;
		for (; j < static_cast<int>(vec.size() - 2); ++j) {
			--i;
			if (abs(height((**i)->left) - height((**i)->right)) == 2) {
				if ((**i)->element < (**(i + 1))->element && (**(i + 1))->element < (**(i + 2))->element) 
					singleRight(**i);
				else if ((**i)->element < (**(i + 1))->element && (**(i + 1))->element >(**(i + 2))->element)
					doubleRight(**i);
				else if ((**i)->element >(**(i + 1))->element && (**(i + 1))->element > (**(i + 2))->element)
					singleLeft(**i);
				else
					doubleLeft(**i);
			}
			renewHeight(**i);
		}
	}
}


template<typename T>
void AVLTree<T>::insert(const T &t)
{
	insert(root, t);
}

template<typename T>
T* AVLTree<T>::deleteMin(AVLNode* &node)
{
	T *tmp;
	if (node->left != nullptr) {
		tmp = deleteMin(node->left);	
		if (height(node->right) - height(node->left) == 2) {
			if (height(node->right->right) >= height(node->right->left))
				singleRight(node);
			else
				doubleRight(node);
		}
	} else {
		tmp = new T(node->element);
		auto old = node;
		node = node->right;
		delete old;
	}
	if (node != nullptr)
		node->height = max(height(node->left), height(node->right)) + 1;
	return tmp;
}

template<typename T>
void AVLTree<T>::remove(const T &t, AVLNode* &node)
{
	if (node == nullptr)
		return;
	else if (t < node->element) {
		remove(t, node->left);
		if (height(node->right) - height(node->left) == 2) {
			if (height(node->right->right) >= height(node->right->left))
				singleRight(node);
			else
				doubleRight(node);
		}
	}
	else if (node->element < t) {
		remove(t, node->right);
		if (height(node->left) - height(node->right) == 2) {
			if (height(node->left->left) >= height(node->left->right))
				singleLeft(node);
			else
				doubleLeft(node);
		}
	}
	else if (node->left != nullptr && node->right != nullptr) {
		auto tmp = deleteMin(node->right);
		node->element = *tmp;
		delete tmp;
		if (height(node->left) - height(node->right) == 2) {
			if (height(node->left->left) >= height(node->left->right))
				singleLeft(node);
			else
				doubleLeft(node);
		}
	}
	else {
		auto old = node;
		node = (node->left != nullptr) ? node->left : node->right;
		delete old;
	}
	if (node != nullptr)
		node->height = max(height(node->left), height(node->right)) + 1;
}

template<typename T>
void AVLTree<T>::remove(const T &t)
{
	remove(t, root);
}

template<typename T>
AVLTree<T>::AVLTree(const AVLTree& b) : root(nullptr)
{
	*this = b;
}

template<typename T>
void AVLTree<T>::copyNode(const AVLNode *from, AVLNode* &to)
{
	if (from != nullptr) {
		to = new AVLNode(from->element);
		copyNode(from->left, to->left);
		copyNode(from->right, to->right);
	}
}

template<typename T>
AVLTree<T>& AVLTree<T>::operator=(const AVLTree &t)
{
	if (this != &t) {
		makeEmpty();
		copyNode(t.root, root);
	}
	return *this;
}

#endif