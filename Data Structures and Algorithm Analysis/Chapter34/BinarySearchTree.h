#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

template<typename T>
class BinarySearchTree
{
public:
	BinarySearchTree(): root(nullptr) {}
	~BinarySearchTree() { makeEmpty(); }
	BinarySearchTree(const BinarySearchTree& b);
	BinarySearchTree& operator=(const BinarySearchTree &t);
	
	const T& findMin() const;
	const T& findMax() const;
	bool contains(const T &t) const;
	bool isEmpty() const;
	void printTree() const;

	void makeEmpty();
	void insert(const T &t);
	void remove(const T &t);
private:
	struct BinaryNode {
		T element;
		BinaryNode* left;
		BinaryNode* right;
		BinaryNode(const T& t, BinaryNode* l = nullptr, BinaryNode* r = nullptr) : element(t), left(l), right(r) {}
	};
	void remove(const T &t, BinaryNode* &node);
	void insert(BinaryNode* &node, const T &t);
	void copyNode(const BinaryNode *from, BinaryNode* &to);
	void makeEmpty(const BinaryNode* node);
	void printNode(const BinaryNode* node) const;
	BinaryNode *root;
};


template<typename T>
const T& BinarySearchTree<T>::findMin() const
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
const T& BinarySearchTree<T>::findMax() const
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
bool BinarySearchTree<T>::contains(const T &t) const
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
bool BinarySearchTree<T>::isEmpty() const
{
	return root == nullptr;
}

template<typename T>
void BinarySearchTree<T>::printNode(const BinaryNode* node) const
{
	if (node != nullptr) {
		printNode(node->left);
		cout << node->element << ends;
		printNode(node->right);
	}
}

template<typename T>
void BinarySearchTree<T>::printTree() const
{
	printNode(root);
}

template<typename T>
void BinarySearchTree<T>::makeEmpty(const BinaryNode* node)
{
	if (node != nullptr) {
		makeEmpty(node->left);
		makeEmpty(node->right);
		delete node;
		node = nullptr;
	}
}

template<typename T>
void BinarySearchTree<T>::makeEmpty()
{
	makeEmpty(root);
}

template<typename T>
void BinarySearchTree<T>::insert(BinaryNode* &node, const T &t)
{
	if (node == nullptr) 
		node = new BinaryNode(t);
	else if (node->element == t)
		;
	else if (node->element < t) 
		insert(node->right, t);
	else
		insert(node->left, t);
}

template<typename T>
void BinarySearchTree<T>::insert(const T &t)
{
	insert(root, t);
}

template<typename T>
void BinarySearchTree<T>::remove(const T &t, BinaryNode* &node)
{
	if (node == nullptr)
		return;
	else if (t < node->element)
		remove(t, node->left);
	else if (node->element < t)
		remove(t, node->right);
	else if (node->left != nullptr && node->right != nullptr) {
		BinaryNode* *tmp = &node->right;
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
void BinarySearchTree<T>::remove(const T &t)
{
	remove(t, root);
}

template<typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree& b) : root(nullptr)
{
	*this = b;
}

template<typename T>
void BinarySearchTree<T>::copyNode(const BinaryNode *from, BinaryNode* &to)
{
	if (from != nullptr) {
		to = new BinaryNode(from->element);
		copyNode(from->left, to->left);
		copyNode(from->right, to->right);
	}
}

template<typename T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(const BinarySearchTree &t)
{
	if (this != &t) {
		makeEmpty();
		copyNode(t.root, root);
	}
	return *this;
}

#endif