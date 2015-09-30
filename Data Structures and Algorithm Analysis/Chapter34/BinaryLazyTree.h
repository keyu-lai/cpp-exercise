#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

template<typename T>
class BinaryLazyTree
{
public:
	BinaryLazyTree(): root(nullptr) {}
	~BinaryLazyTree() { makeEmpty(); }
	BinaryLazyTree(const BinaryLazyTree& b);
	BinaryLazyTree& operator=(const BinaryLazyTree &t);ddd
	
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
		bool exist;
		BinaryNode(const T& t, BinaryNode* l = nullptr, BinaryNode* r = nullptr, bool e = true) 
			: element(t), left(l), right(r), exist(e) {}
	};
	bool isEmpty(BinaryNode* const &node) const;
	void remove(const T &t, BinaryNode* &node);
	void insert(BinaryNode* &node, const T &t);
	void copyNode(const BinaryNode *from, BinaryNode* &to);
	void makeEmpty(BinaryNode* &node);
	void printNode(const BinaryNode* node) const;
	BinaryNode *root;
};


template<typename T>
const T& BinaryLazyTree<T>::findMin() const
{
	if (isEmpty())
		throw runtime_error("Try to use an empty tree!");
	else {
		auto node = root, tmp = root;
		while (node->left != nullptr) {
			if (node->left->exist)
				tmp = node->left;
			node = node->left;
		}
		return tmp->element;
	}
}

template<typename T>
const T& BinaryLazyTree<T>::findMax() const
{
	if (isEmpty())
		throw runtime_error("Try to use an empty tree!");
	else {
		auto node = root, tmp = root;
		while (node->right != nullptr) {
			if (node->right->exist)
				tmp = node->right;
			node = node->right;
		}
		return tmp->element;
	}
}

template<typename T>
bool BinaryLazyTree<T>::contains(const T &t) const
{
	if (isEmpty())
		return false;
	else {
		auto node = root;
		while (node != nullptr) {
			if (node->element == t) {
				if (node->exist)
					return true;
				else
					return false;
			}
			else if (node->element < t)
				node = node->right;
			else
				node = node->left;
		}
		return false;
	}
}

template<typename T>
bool BinaryLazyTree<T>::isEmpty(BinaryNode* const &node) const
{
	if (node != nullptr) {
		if (node->exist)
			return false;
		else
			return isEmpty(root->left) && isEmpty(root->right);
	}
	else
		return true;
}

template<typename T>
bool BinaryLazyTree<T>::isEmpty() const
{
	return isEmpty(root);
}

template<typename T>
void BinaryLazyTree<T>::printNode(const BinaryNode* node) const
{
	if (node != nullptr) {
		printNode(node->left);
		if (node->exist)
			cout << node->element << ends;
		printNode(node->right);
	}
}

template<typename T>
void BinaryLazyTree<T>::printTree() const
{
	printNode(root);
}

template<typename T>
void BinaryLazyTree<T>::makeEmpty(BinaryNode* &node)
{
	if (node != nullptr) {
		makeEmpty(node->left);
		makeEmpty(node->right);
		delete node;
		node = nullptr;
	}
}

template<typename T>
void BinaryLazyTree<T>::makeEmpty()
{
	makeEmpty(root);
}

template<typename T>
void BinaryLazyTree<T>::insert(BinaryNode* &node, const T &t)
{
	if (node == nullptr) 
		node = new BinaryNode(t);
	else if (node->element == t) {
		if (!node->exist)
			node->exist = true;
	}
	else if (node->element < t) 
		insert(node->right, t);
	else
		insert(node->left, t);
}

template<typename T>
void BinaryLazyTree<T>::insert(const T &t)
{
	insert(root, t);
}

template<typename T>
void BinaryLazyTree<T>::remove(const T &t, BinaryNode* &node)
{
	if (node == nullptr)
		return;
	else if (t < node->element)
		remove(t, node->left);
	else if (node->element < t)
		remove(t, node->right);
	else {
		if (node->exist)
			node->exist = false;
	}
}

template<typename T>
void BinaryLazyTree<T>::remove(const T &t)
{
	remove(t, root);
}

template<typename T>
BinaryLazyTree<T>::BinaryLazyTree(const BinaryLazyTree& b) : root(nullptr)
{
	*this = b;
}

template<typename T>
void BinaryLazyTree<T>::copyNode(const BinaryNode *from, BinaryNode* &to)
{
	if (from != nullptr) {
		to = new BinaryNode(from->element);
		copyNode(from->left, to->left);
		copyNode(from->right, to->right);
	}
}

template<typename T>
BinaryLazyTree<T>& BinaryLazyTree<T>::operator=(const BinaryLazyTree &t)
{
	if (this != &t) {
		makeEmpty();
		copyNode(t.root, root);
	}
	return *this;
}

#endif