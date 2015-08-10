#ifndef BINOMIAL_QUEUES_H
#define BINOMIAL_QUEUES_H

#include <vector>

template<typename T>
class BinomailQueues
{
public:
	BinomialQueues();
	BinomialQueues(const T &item);
	BinomialQueues(const BinomialQueues &rhs);
	~BinomialQueues();

	bool isEmpty() const;
	const T& findMin() const;
	void insert();
	void deleteMin();
	void deleteMin(T& minItem);

	void makeEmpty();
	void merge(BinomialQueues &rhs);
	const BinomialQueues& operator=(const BinomialQueues &rhs);

private:
	struct BinomialNode {
		T element;
		BinomialNode *leftChild;
		BinomialNode *nextSibling;
		BinomialNode(const T &t, BinomialNode *l = nullptr, BinomialNode *n = nullptr) :
			element(t), leftChild(l), nextSibling(n);
	};
	int currentSize;
	std::vector<BinomialNode*> theTrees;

	int findMinIndex() const;
	int capacity() const;
	BinomialNode* combineTrees(BinomialNode *t1, BinomialNode *t2);
	void makeEmpty(BinomialNode* &t);
	BinomialNode* clone(BinomialNode *t) const;
};

template<typename T>
typename BinomailQueues<T>::BinomialNode* BinomailQueues<T>::combineTrees(BinomialNode *t1, BinomialNode *t2)
{
	if (t2->element < t1->element)
		return combineTrees(t2, t1);
	t2->nextSibling = t1->leftChild;
	t1->leftChild = t2;
	return t1;
}




#endif 