#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <limits>
#include <cmath>
#include <algorithm>
#include <list>
#include "SkipList.h"

using namespace std;

//// 10.16
//struct Point
//{
//	double x;
//	double y;
//	Point(double a = 0, double b = 0) : x(a), y(b) { }
//};
//
//double disPo(const Point &a, const Point &b)
//{
//	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
//}
//
//double bruteDis(vector<Point>::iterator &a, vector<Point>::iterator &b)
//{
//	double dis = numeric_limits<double>::max(), tmp;
//	for (auto i = a; i != b; ++i) {
//		for (auto j = i + 1; j != b; ++j) {
//			if ((tmp = disPo(*i, *j)) < dis)
//				dis = tmp;
//		}
//	}
//	return dis;
//}
//
//double min(double a, double b)
//{
//	return a < b ? a : b;
//}
//
//double minDis(vector<Point>::iterator a, vector<Point>::iterator b, vector<Point>::iterator c, vector<Point>::iterator d)
//{
//	if (b - a < 4)
//		return bruteDis(a, b);
//	auto mid = a + (b - a) / 2;
//	double x_mid = ((mid - 1)->x + mid->x) / 2;;
//	vector<Point> y_left, y_right;
//	if ((mid - 1)->x != mid->x) {
//		for (auto i = c; i != d; ++ i) {
//			if (i->x < x_mid)
//				y_left.push_back(*i);
//			else 
//				y_right.push_back(*i);
//		}
//	} else {
//		auto eq_front = mid - 1, eq_back = mid;
//		while (eq_front != a && (eq_front - 1)->x == x_mid) --eq_front;
//		while (eq_back != b && (++eq_back)->x == x_mid);
//		vector<bool> mark(eq_back - eq_front, false);
//		int mark_mid = mid - eq_front;
//		for (auto i = c; i != d; ++i) {
//			if (i->x < x_mid) 
//				y_left.push_back(*i);
//			else if (i->x > x_mid)
//				y_right.push_back(*i);
//			else {
//				int k = 0;
//				for (vector<Point>::iterator j = eq_front; j != eq_back; ++j, ++k) {
//					if (!mark[k] && j->y == i->y) {
//						if (k < mark_mid) y_left.push_back(*i);
//						else y_right.push_back(*i);
//						mark[k] = true;
//						break;
//					}
//				}
//			}
//		}
//	}
//	double delta = min(minDis(a, mid, y_left.begin(), y_left.end()), minDis(mid, b, y_right.begin(), y_right.end()));
//	vector<Point> y_strip;
//	for (auto i = c; i != d; ++i) {
//		if (i->x > x_mid - delta && i->x < x_mid + delta)
//			y_strip.push_back(*i);
//	}
//	for (auto i = y_strip.begin(); i != y_strip.end(); ++i) {
//		for (auto j = i + 1; j != y_strip.end(); ++j) {
//			if (abs(i->y - j->y) > delta)
//				break;
//			else
//				delta = min(disPo(*i, *j), delta);
//		}
//	}
//	return delta;
//}
//
//double minDis(vector<Point>& vec)
//{
//	vector<Point> x_vec(vec), y_vec(vec);
//	sort(x_vec.begin(), x_vec.end(), [](const Point &a, const Point &b)
//										{return a.x < b.x; });
//	sort(y_vec.begin(), y_vec.end(), [](const Point &a, const Point &b)
//										{return a.y < b.y; });
//	return minDis(x_vec.begin(), x_vec.end(), y_vec.begin(), y_vec.end());
//}
//
//int main()
//{
//	default_random_engine e(static_cast<unsigned>(time(0)));
//	uniform_int_distribution<int> u(-1000, 1000);
//	vector<Point> vec;
//	for (size_t i = 0; i < 20; ++i)
//		vec.push_back(Point(u(e), u(e)));
//	cout << minDis(vec) << endl;
//	cout << bruteDis(vec.begin(), vec.end());
//	return 0;
//}

// 10.40
//bool place(vector<int> &x, list<int> d, int n, int left, int right)
//{
//	int dmax;
//	bool found = false;
//
//	if (d.empty())
//		return true;
//
//	dmax = d.back();
//	list<int> tmp(d);
//	bool mark;
//	for (auto j = 0; j < n; ++j) {
//		if (j == left) {
//			j = right;
//			continue;
//		}
//		mark = false;
//		for (auto i = d.begin(); i != d.end(); ++i) {
//			if (abs(x[j] - dmax) == *i) {
//				d.erase(i); 
//				mark = true;
//				break;
//			} 
//		}
//		if (!mark)
//			break;
//	}
//	if (mark) {
//		x[right] = dmax;		
//		found = place(x, d, n, left, right - 1);
//	} 
//	if (!(mark && found)) 
//		d = tmp;
//
//	if (!found) {
//		for (auto j = 0; j < n; ++j) {
//			if (j == left) {
//				j = right;
//				continue;
//			}
//			mark = false;
//			for (auto i = d.begin(); i != d.end(); ++i) {
//				if (abs(x[n - 1] - dmax - x[j]) == *i) {
//					d.erase(i);
//					mark = true;
//					break;
//				}
//			}
//			if (!mark)
//				break;
//		}
//		if (mark) {
//			x[left] = x[n - 1] - dmax;
//			found = place(x, d, n, left + 1, right);
//		}
//		if (!(mark && found))
//			d = tmp;
//	}
//
//	return found;
//}
//
//bool turnpike(vector<int> &x, list<int> d, int n)
//{
//	x.resize(n, 0);
//	x[0] = 0;
//	x[n - 1] = d.back();
//	d.pop_back();
//	x[n - 2] = d.back();
//	d.pop_back();
//	for (auto i = d.begin(); i != d.end(); ++i) {
//		if (*i == x[n - 1] - x[n - 2]) {
//			d.erase(i);
//			return place(x, d, n, 1, n - 3);
//		}
//	}
//	return false;
//}

//10.41 & 10.42(the solution in the book is better)
//bool place(vector<vector<int>> &x, list<int> d, int n, int &count, int left, int right)
//{
//	int dmax;
//	bool found = false;
//
//	if (d.empty())
//		return true;
//
//	dmax = d.back();
//	list<int> tmp(d);
//	vector<int> xtmp(x[count - 1]);
//	bool mark;
//	for (auto j = 0; j < n; ++j) {
//		if (j == left) {
//			j = right;
//			continue;
//		}
//		mark = false;
//		for (auto i = d.begin(); i != d.end(); ++i) {
//			if (abs(x[count - 1][j] - dmax) == *i) {
//				d.erase(i);
//				mark = true;
//				break;
//			}
//		}
//		if (!mark)
//			break;
//	}
//	if (mark) {
//		x[count - 1][right] = dmax;
//		found = place(x, d, n, count, left, right - 1);
//	}
//	if (!(mark && found))
//		d = tmp;
//
//	bool flag = false;
//	if (found) {
//		x.push_back(xtmp);
//		++count;
//		d = tmp;
//		flag = true;
//	}
//	for (auto j = 0; j < n; ++j) {
//		if (j == left) {
//			j = right;
//			continue;
//		}
//		mark = false;
//		for (auto i = d.begin(); i != d.end(); ++i) {
//			if (abs(x[count - 1][n - 1] - dmax - x[count - 1][j]) == *i) {
//				d.erase(i);
//				mark = true;
//				break;
//			}
//		}
//		if (!mark)
//			break;
//	}
//	if (mark) {
//		x[count - 1][left] = x[count - 1][n - 1] - dmax;
//		found = place(x, d, n, count, left + 1, right);
//	}
//	if (flag) {
//		if (!(mark && found)) {
//			x.pop_back();
//			--count;
//		}
//	}
//	return found;
//}
//
//bool turnpike(vector<vector<int>> &x, list<int> d, int n)
//{
//	int count = 1;
//	x.resize(1);
//	x[0].resize(n, 0);
//	x[0][0] = 0;
//	x[0][n - 1] = d.back();
//	d.pop_back();
//	x[0][n - 2] = d.back();
//	d.pop_back();
//	for (auto i = d.begin(); i != d.end(); ++i) {
//		if (*i == x[0][n - 1] - x[0][n - 2]) {
//			d.erase(i);
//			return place(x, d, n, count, 1, n - 3);
//		}
//	}
//	return false;
//}

// 10.59

//void moveFor(pair<int, int> &now, int ori)
//{
//	switch (ori) {
//	case 0: 
//		now.first -= 2;
//		now.second -= 1;
//		break;
//	case 1:
//		now.first -= 1;
//		now.second -= 2;
//		break;
//	case 2:
//		now.first += 1;
//		now.second -= 2;
//		break;
//	case 3:
//		now.first += 2;
//		now.second -= 1;
//		break;
//	case 4:
//		now.first += 2;
//		now.second += 1;
//		break;
//	case 5:
//		now.first += 1;
//		now.second += 2;
//		break;
//	case 6:
//		now.first -= 1;
//		now.second += 2;
//		break;
//	case 7:
//		now.first -= 2;
//		now.second += 1;
//		break;
//	}
//}
//
//void moveBack(pair<int, int> &now, int ori)
//{
//	switch (ori) {
//	case 0:
//		now.first += 2;
//		now.second += 1;
//		break;
//	case 1:
//		now.first += 1;
//		now.second += 2;
//		break;
//	case 2:
//		now.first -= 1;
//		now.second += 2;
//		break;
//	case 3:
//		now.first -= 2;
//		now.second += 1;
//		break;
//	case 4:
//		now.first -= 2;
//		now.second -= 1;
//		break;
//	case 5:
//		now.first -= 1;
//		now.second -= 2;
//		break;
//	case 6:
//		now.first += 1;
//		now.second -= 2;
//		break;
//	case 7:
//		now.first += 2;
//		now.second -= 1;
//		break;
//	}
//}
//
//void oneStep(const pair<int, int> begin, pair<int, int> &now, vector<vector<int>> &mark, const int &B, int &count)
//{
//	for (int i = 0; i < 8; ++i) {
//		if (count < B * B ) {
//			moveFor(now, i);
//			if (now.first >= 0 && now.second >= 0 && now.first < B && now.second < B && mark[now.first][now.second] == 0) {
//				++count;
//				mark[now.first][now.second] = count;
//				oneStep(begin, now, mark, B, count);
//				if (count == B * B) {
//					auto x = abs(begin.first - now.first), y = abs(begin.second - now.second);
//					if ((x == 2 && y == 1) && (x == 1 && y == 2))
//						break;
//				}
//				--count;
//				mark[now.first][now.second] = 0;
//			}
//			moveBack(now, i);
//		}
//	}
//}
//
//bool knight(vector<vector<int>> &mark, const int B)
//{
//	if (B % 2 == 0) {
//		int count;
//		pair<int, int> now, begin;
//		for (auto i = 0; i < B; ++i) {
//			for (auto j = 0; j < B; ++j) {
//				cout << i * B + j << ends;
//				now.first = begin.first = i;
//				now.second = begin.second = j;
//				mark = vector<vector<int>>(B, vector<int>(B, 0));
//				mark[i][j] = 1;
//				count = 1;
//				oneStep(begin, now, mark, B, count);
//				if (count == B * B)
//					return true;
//			}
//		}
//	}
//	return false;
//}
//
//int main()
//{
//	int B = 6;
//	vector<vector<int>> mark(B, vector<int>(B, 0));
//	knight(mark, B);
//	cout << endl;
//	for (auto &i : mark) {
//		for (auto &j : i)
//			cout << j << ends;
//		cout << endl;
//	}
//	return 0;
//}

