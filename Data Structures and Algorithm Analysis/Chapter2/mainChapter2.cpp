#include <vector>
#include <iostream>
#include <list>
#include <iterator>
#include <limits>
#include <cmath>

using namespace std;

///*  2.15  */
//int findEq(vector<int> &vec)
//{
//	auto a = vec.begin(), b = vec.end();
//	auto idx = a + (b - a) / 2;
//	while ((idx - vec.begin() + 1) != *idx) {
//		if ((idx - vec.begin() + 1) < *idx) {
//			b = idx;
//		} else {
//			a = idx + 1;
//		}	
//		idx = a + (b - a) / 2;
//		if (a >= b) return -1;
//	}
//	return *idx;
//}

///*  2.16  */
//int gcdIn(int a, int b);
//int gcd(int a, int b);
//int gcdIn(int a, int b)
//{
//	if (b != 1) {
//		if (a % 2 == 0) {
//			if (b % 2 == 0)
//				return 2 * gcdIn(a / 2, b / 2);
//			else
//				return gcd(a / 2, b);
//		}
//		else {
//			if (b % 2 == 0)
//				return gcdIn(a, b / 2);
//			else
//				return gcdIn((a + b) / 2, (a - b) / 2);
//		}
//	}
//	else
//		return 1;
//}
//
//int gcd(int a, int b)
//{
//	return a = b ? a : (a > b ? gcdIn(a, b) : gcdIn(b, a));
//}

///*  2.17c  */
//double min(double x, double y) { return x < y ? x : y; }
//double max(double x, double y) { return x > y ? x : y; }
//double findMaxPro(vector<double> &vec)
//{
//	double curMax = 1, curMin = 1;
//	double findMax = (numeric_limits<double>::min)();
//	for (auto &c : vec) {
//		if (c > 0) {
//			curMax = curMax * c;
//			curMin = min(curMin *c, 1);
//		} else if (c < 0) {
//			auto tmp = curMin;
//			curMin = curMax * c;
//			curMax = max(tmp * c, 1);
//		} else { 
//			curMin = 1;
//			curMax = 1;
//		}
//		if (curMax > findMax)
//			findMax = curMax;
//	}
//	return findMax;
//}
//double find(vector<double> &a)
//{
//	double maxSum = (numeric_limits<double>::min)();
//	for (size_t i = 0; i < a.size(); i++) {
//		double thisSum = 1;
//		for (size_t j = i; j < a.size(); j++) {
//			thisSum *= a[j];
//			if (thisSum > maxSum)
//				maxSum = thisSum;
//		}
//	}
//	return maxSum;
//}


///*  2.17b very bad  */
//int sum(vector<int>::iterator &begin, vector<int>::iterator &end)
//{
//	int sum = 0;
//	for (auto i = begin; i != end; ++i)
//		sum += *i;
//	return sum;
//}
//int findMinPos(vector<int>::iterator &begin, vector<int>::iterator &end)
//{
//	if (begin == end - 1)
//		return  *begin > 0 ? *begin: 0;
//	auto mid = begin + (end - begin) / 2;
//	auto left = findMinPos(begin, mid);
//	auto right = findMinPos(mid, end);
//	int middle = (numeric_limits<int>::max)();
//	for (auto i = mid; i != begin; --i) {
//		for (auto j = mid; j != end; ++j) {
//			auto tmp = sum(i-1, j+1);
//			if (tmp < middle && tmp >0)
//				middle = tmp;
//		}
//	}
//	int tmp = 0;
//	if (left == 0)
//		tmp = right;
//	else if (right == 0)
//		tmp = left;
//	else
//		tmp = left < right ? left : right;
//	if (tmp == 0)
//		return middle;
//	else if (middle == 0)
//		return tmp;
//	else
//		return tmp < middle ? tmp: middle;
//
//}
//
//int find(vector<int> &a)
//{
//	int maxSum = (numeric_limits<int>::max)();
//	for (size_t i = 0; i < a.size(); i++) {
//		int thisSum = 0;
//		for (size_t j = i; j < a.size(); j++) {
//			thisSum += a[j];
//			if (thisSum < maxSum && thisSum > 0)
//				maxSum = thisSum;
//		}
//	}
//	return maxSum;
//}

///*  2.23  */
//double expWithoutRecursion(double e, unsigned exp)
//{
//	if (exp > 1) {
//		unsigned count = static_cast<unsigned>(log2(exp)) + 1;
//		double re = 1;
//		for (size_t i = 0; i < count; ++i) {
//			if (exp % 2)
//				re = re * e;
//			re = re * re;
//			exp = exp / 2;
//		}
//		return re;
//	}
//	else
//		return e;
//}

///*  2.28b  */
//int maxD(vector<int> &vec)
//{
//	auto min = vec.begin();
//	auto max = *(vec.begin() + 1) - *vec.begin();
//	for (auto i = vec.begin() + 1; i != vec.end(); ++i) {
//		if (*min > *(i-1)) 
//			min = i - 1;
//		if (max < (*i - *min))
//			max = (*i - *min);
//	}
//	return max;
//}

///*  2.26  */
//bool twoEq(int &a, int &b)
//{
//	if (a == b)
//		return true;
//	else
//		return false;
//}
//
//vector<int>* candidate(vector<int> *vec)
//{
//	auto a = vec->begin(), b = vec->end();
//	if (b - a <= 2)
//		return vec;
//	vector<int> *re = new vector<int>();
//	for (auto i = 0; i < (b - a) / 2; ++i) {
//		if (twoEq(*(a + 2 * i), *(a + 1 + 2 * i))) {
//			re->push_back(*(a + 2 * i));
//		}
//	}
//	if ((b - a) % 2 == 1)
//		re->push_back(*(b - 1));
//	delete vec;
//	return candidate(re);
//}
//
//int majority(vector<int> &vec)
//{
//	vector<int> *vecCopy = new vector<int>(vec);
//	auto re = candidate(vecCopy);
//	size_t count = 0;
//	for (auto &c : *re) {
//		for (auto &cc : vec)
//			if (cc == c) ++count;
//		if (count > vec.size() / 2) {
//			auto tmp = c;
//			delete re;
//			return tmp;
//		}
//		count = 0;
//	}
//	delete re;
//	return -1;
//}


int main()
{
	vector<int> vec{1,3,3,2,3,3,2,3,3,2,2,3,3,3};
	cout << majority(vec) << endl;
	return 0;
}