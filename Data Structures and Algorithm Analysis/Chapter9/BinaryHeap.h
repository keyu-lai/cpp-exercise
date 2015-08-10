#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <vector>
#include <stdexcept>
#include <algorithm>

template<typename T>
class BinaryHeap
{
public:
	explicit BinaryHeap(size_t capacity = 100) : vec(capacity) { }
	explicit BinaryHeap(const std::vector<T> &items);
	bool isEmpty() const;
	const T& findMin() const;

	void insert(const T &t);
	void deleteMin();
	void deleteMin(T &minItem);
	void makeEmpty();
	void print() {
		if (currentSize == 0)
			throw runtime_error("no element in the heap!");
		for (size_t i = 1; i <= currentSize; ++i)
			cout << *(vec.begin() + i) << ends;
	}
private:
	size_t currentSize;
	std::vector<T> vec;
	void buildHeap();
	void percolateDown(size_t hole);
	void percolateUp(size_t hole);
};

template<typename T>
BinaryHeap<T>::BinaryHeap(const std::vector<T> &items) : vec(items.size() + 10), currentSize(items.size()) 
{
	copy(items.begin(), items.end(), vec.begin() + 1);
	buildHeap();
}

template<typename T>
void BinaryHeap<T>::percolateUp(size_t hole)
{
	auto t = vec[hole];
	while (hole > 1 && t < vec[hole / 2]) {
		vec[hole] = vec[hole / 2];
		hole /= 2;
	}
	vec[hole] = t;
}

template<typename T>
void BinaryHeap<T>::insert(const T &t)
{
	if (currentSize == vec.size() - 1)
		vec.resize(2 * vec.size());
	auto hole = ++currentSize;
	vec[hole] = t;
	percolateUp(hole);
}

template<typename T>
void BinaryHeap<T>::percolateDown(size_t hole)
{
	auto t = vec[hole];
	auto next = hole;
	while (2 * hole <= currentSize) {
		next = hole * 2;
		if (next != currentSize && vec[next + 1] < vec[next])
			++next;
		if (vec[next] < t)
			vec[hole] = vec[next];
		else
			break;
		hole = next;
	}
	vec[hole] = t;
}

template<typename T>
void BinaryHeap<T>::deleteMin()
{
	if (currentSize == 0)
		throw runtime_error("no element in the heap!");
	vec[1] = vec[currentSize--];
	percolateDown(1);
}

template<typename T>
bool BinaryHeap<T>::isEmpty() const
{
	return !(currentSize >= 1);
}

template<typename T>
const T& BinaryHeap<T>::findMin() const
{
	if (currentSize() == 0)
		throw runtime_error("no element in the heap!");
	return vec[1];
}

template<typename T>
void BinaryHeap<T>::deleteMin(T &minItem)
{
	if (currentSize() == 0)
		throw runtime_error("no element in the heap!");
	minItem = vec[1];
	vec[1] = vec[currentSize--];
	percolateDown(1);
}

template<typename T>
void BinaryHeap<T>::makeEmpty()
{
	currentSize = 0;
}


template<typename T>
void BinaryHeap<T>::buildHeap()
{
	for (auto i = currentSize / 2; i != 1; i--)
		percolateDown(i);
}

#endif




