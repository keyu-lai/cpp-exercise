#ifndef MY_SET_H
#define MY_SET_H

template<typename T>
class MySet
{
private:
	struct BinaryNode {
		T element;
		BinaryNode *parent;
		BinaryNode *left;
		BinaryNode *right;
		BinaryNode(const T& t, BinaryNode* p = nullptr, BinaryNode* l = nullptr, BinaryNode* r = nullptr) : element(t), parent(p), left(l), right(r) {}
	};
public:
	MySet(): root(nullptr) {}
	~MySet() { makeEmpty(); }
	MySet(const MySet& b);
	MySet& operator=(const MySet &t);
	
	const T& findMin() const;
	const T& findMax() const;
	bool contains(const T &t) const;
	bool isEmpty() const;
	void printTree() const;

	void makeEmpty();
	void remove(const T &t);
	class const_iterator{
	protected:
		friend MySet;
		BinaryNode *node;
	public:
		const_iterator(BinaryNode* n = nullptr) : node(n) {}
		const T& operator*() const { return node->element; }
		const_iterator& operator++() {
			BinaryNode *tmp;
			if (node->right != nullptr) {
				tmp = node->right;
				while (tmp->left != nullptr)
					tmp = tmp->left;
				node = tmp;
			}
			else {
				tmp = node->parent;
				if (tmp->element > node->element) {
					while (tmp->parent->element < tmp->element && tmp->parent->element >node->element)
						tmp = tmp->parent;
					node = tmp;
				}
			}
			return *this;
		}
		const_iterator operator++ (int) {
			const_iterator old = *this;
			++(*this);
			return old;
		}
		bool operator== (const const_iterator & rhs) const { return node == rhs.node; }
		bool operator!= (const const_iterator & rhs) const { return !(*this == rhs); }
	};
	class iterator : public const_iterator {
	public:
		iterator(BinaryNode* n = nullptr) : const_iterator(n) {}
		T& operator* () { return node->element; }
		const T& operator* () const { return node->element; }
		iterator& operator++ ()
		{
			BinaryNode *tmp;
			if (node->right != nullptr) {
				tmp = node->right;
				while (tmp->left != nullptr)
					tmp = tmp->left;
				node = tmp;
			}
			else {				
				tmp = node->parent;
				if (tmp->element > node->element) {
					while (tmp->parent->element < tmp->element && tmp->parent->element >node->element)
						tmp = tmp->parent;
					node = tmp;
				}
			}
			return *this;
		}
		iterator operator++ (int)
		{
			iterator old = *this;
			++(*this);
			return old;
		}
	};
	iterator insert(const T &x) {
		return (insert(x, root, root));
	}
	iterator begin()
	{
		BinaryNode *t = root;
		while (t->left)
			t = t->left;
		return iterator(t);
	}
private:
	iterator insert(const T& x, BinaryNode* &t,BinaryNode* &p) 
	{
		if (t == nullptr)
		{
			t = new BinaryNode(x, p, nullptr, nullptr);
			return iterator(t);
		}
		else if (x < t->element)
			return (insert(x, t->left, t));
		else if (t->element < x) 
			return (insert(x, t->right, t));
		return iterator(t);
	}
	void remove(const T &t, BinaryNode* &node);
	void copyNode(const BinaryNode *from, BinaryNode* &to);
	void makeEmpty(const BinaryNode* node);
	void printNode(const BinaryNode* node) const;
	BinaryNode *root;
};


template<typename T>
const T& MySet<T>::findMin() const
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
const T& MySet<T>::findMax() const
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
bool MySet<T>::contains(const T &t) const
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
bool MySet<T>::isEmpty() const
{
	return root == nullptr;
}

template<typename T>
void MySet<T>::printNode(const BinaryNode* node) const
{
	if (node != nullptr) {
		printNode(node->left);
		cout << node->element << ends;
		printNode(node->right);
	}
}

template<typename T>
void MySet<T>::printTree() const
{
	printNode(root);
}

template<typename T>
void MySet<T>::makeEmpty(const BinaryNode* node)
{
	if (node != nullptr) {
		makeEmpty(node->left);
		makeEmpty(node->right);
		delete node;
		node = nullptr;
	}
}

template<typename T>
void MySet<T>::makeEmpty()
{
	makeEmpty(root);
}

template<typename T>
void MySet<T>::remove(const T &t, BinaryNode* &node)
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
void MySet<T>::remove(const T &t)
{
	remove(t, root);
}

template<typename T>
MySet<T>::MySet(const MySet& b) : root(nullptr)
{
	*this = b;
}

template<typename T>
void MySet<T>::copyNode(const BinaryNode *from, BinaryNode* &to)
{
	if (from != nullptr) {
		to = new BinaryNode(from->element);
		copyNode(from->left, to->left);
		copyNode(from->right, to->right);
	}
}

template<typename T>
MySet<T>& MySet<T>::operator=(const MySet &t)
{
	if (this != &t) {
		makeEmpty();
		copyNode(t.root, root);
	}
	return *this;
}

#endif