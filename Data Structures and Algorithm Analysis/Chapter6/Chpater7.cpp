#include <iostream>
#include <vector>

using namespace std;

//// 7.16
//template<typename T>
//void merge(vector<T> &a, vector<T> tmp, int leftPos, int rightPos, int rightEnd)
//{
//	int leftEnd = rightPos - 1;
//	int tmpPos = leftPos;
//	int numElements = rightEnd - leftPos + 1;
//
//	while (leftPos <= leftEnd && rightPos <= rightEnd) {
//		if (a[leftPos] <= a[rightPos])
//			tmp[tmpPos++] = a[leftPos++];
//		else
//			tmp[tmpPos++] = a[rightPos++];
//	}
//
//	while (leftPos <= leftEnd)
//		tmp[tmpPos++] = a[leftPos++];
//	while (rightPos <= rightEnd) 
//		tmp[tmpPos++] = a[rightPos++];
//
//	for (int i = 0; i < numElements; ++i, --rightEnd)
//		a[rightEnd] = tmp[rightEnd];
//}
//
//template<typename T>
//void mergesort(vector<T> &a)
//{
//	int size = a.size(), i = 2;
//	vector<T> tmp(size);
//	for (; i <= size; i *= 2) {
//		int start = 0;
//		for (; start + i <= size; start += i)
//			merge(a, tmp, start, start + i / 2, start + i - 1);
//		if (size - start > i / 2)
//			merge(a, tmp, start, start + i / 2, size - 1);
//	}
//	i /= 2;
//	merge(a, tmp, 0, i, size - 1);
//}

template <typename Comparable>
void insertionSort(vector<Comparable> & a, int left, int right)
{
	for (int p = left + 1; p <= right; p++)
	{
		Comparable tmp = a[p];
		int j;

		for (j = p; j > left && tmp < a[j - 1]; j--)
			a[j] = a[j - 1];
		a[j] = tmp;
	}
}

//template<typename T>
//const T& median3(vector<T> &a, int left, int right)
//{
//	int center = (left + right) / 2;
//	if (a[center] < a[left])
//		swap(a[left], a[center]);
//	if (a[right] < a[left])
//		swap(a[left], a[right]);
//	if (a[right] < a[center])
//		swap(a[center], a[right]);
//	swap(a[center], a[right - 1]);
//	return a[right - 1];
//}

//template<typename T>
//void quicksort(vector<T> &a, int left, int right)
//{
//	if (left + 10 < right) {
//		T pivot = median3(a, left, right);
//		int i = left, j = right - 1;
//		while (true) {
//			while (a[++i] < pivot) {}
//			while (a[--j] > pivot) {}
//			if (i < j)
//				swap(a[i], a[j]);
//			else
//				break;
//		}
//		swap(a[i], a[right - 1]);
//		quicksort(a, left, i - 1);
//		quicksort(a, i + 1, right);
//	}
//	else
//		insertionSort(a, left, right);
//}

//// 7.25 
//template<typename T>
//void quicksort(vector<T> &a, int left, int right)
//{
//	while(true) {
//		if (left + 10 >= right) {
//			insertionSort(a, left, right);
//			return;
//		}
//		else {
//			T pivot = median3(a, left, right);
//			int i = left, j = right - 1;
//			while (true) {
//				while (a[++i] < pivot) {}
//				while (a[--j] > pivot) {}
//				if (i < j)
//					swap(a[i], a[j]);
//				else
//					break;
//			}
//			swap(a[i], a[right - 1]);
//			quicksort(a, left, i - 1);
//			left = i + 1;
//		}
//	}
//}

// 7.26
//template<typename T>
//void quicksort(vector<T> &a, int left, int right)
//{
//	while (true) {
//		if (left + 10 >= right) {
//			insertionSort(a, left, right);
//			return;
//		}
//		T pivot = median3(a, left, right);
//		int i = left, j = right - 1;
//		while (true) {
//			while (a[++i] < pivot) {}
//			while (a[--j] > pivot) {}
//			if (i < j)
//				swap(a[i], a[j]);
//			else
//				break;
//		}
//		swap(a[i], a[right - 1]);
//		if (i - left > right - i) {
//			quicksort(a, i + 1, right);
//			right = i - 1;
//		}
//		else {
//			quicksort(a, left, i - 1);
//			left = i + 1;
//		}
//	}
//}

// 7.28
//template<typename T>
//const T& median3(vector<T> &a, int left, int right)
//{
//	int center = (left + right) / 2;
//	if (a[center] < a[left])
//		swap(a[left], a[center]);
//	if (a[right] < a[left])
//		swap(a[left], a[right]);
//	if (a[right] < a[center])
//		swap(a[center], a[right]);
//	return a[center];
//}
//template<typename T>
//void quicksort(vector<T> &a, int left, int right)
//{
//	if (left + 10 < right) {
//		T pivot = median3(a, left, right);
//		int i = left, j = right, m = left, n = right;
//		while (true) {
//			while (a[++i] <= pivot) {
//				if (a[i] == pivot)
//					swap(a[i], a[m++]);
//				if (i == j)
//					break;
//			}
//			if (i < j) {
//				while (a[--j] >= pivot) {
//					if (a[j] == pivot)
//						swap(a[j], a[n--]);
//					if (i == j)
//						break;
//				}
//			}
//			if (i < j) 
//				swap(a[i], a[j]);
//			else
//				break;
//		}
//		for (auto k = right, idx = 0; idx < n - j + 1; ++idx, --k)
//			a[k] = a[n - idx];
//		for (auto k = left, idx = 0; idx < i - m; ++idx, ++k)
//			a[k] = a[m + idx];
//		for (auto k = 0; k < right - n + m - left;  ++k)
//			a[left + i - m + k] = pivot;
//		quicksort(a, left, left + i- m - 1);
//		quicksort(a, right - n + j, right);
//	}
//	else
//		insertionSort(a, left, right);
//}

template<typename T>
void quicksort(vector<T> &a)
{
	quicksort(a, 0, a.size() - 1);
}


// 7.40
enum State{FALSE, MAYBE, TRUE};

void threeSort(vector<State> &a)
{
	int left = -1, right = a.size();
	while (true) {
		while (a[++left] == FALSE) {
			if (left == a.size() - 1) break;
		}
		while (a[--right] != FALSE) {
			if (right == 0) break;
		}
		if (left < right)
			swap(a[left], a[right]);
		else
			break;
	}
	if (a[a.size() - 1] == FALSE) 
		return;
	else if (a[0] != FALSE) {
		left = -1;
		right = a.size();
	} else {
		left = left - 1;
		right = a.size();
	}
	while (true) {
		while (a[++left] == MAYBE) {
			if (left == a.size() - 1) break;
		}
		while (a[--right] == TRUE) {
			if (right == 0) break;
		}
		if (left < right)
			swap(a[left], a[right]);
		else
			break;
	}
}


int main()
{
	// vector<int> vec{3,45,76,8,57,286,8,34,12,1,8,453,7653,8,323,767,8,123,8986,8,8};
	vector<State> vec{ MAYBE, MAYBE, MAYBE, MAYBE, MAYBE, MAYBE, };
	threeSort(vec);
	for (auto &c : vec)
		cout << c << ends;
	return 0;
}

