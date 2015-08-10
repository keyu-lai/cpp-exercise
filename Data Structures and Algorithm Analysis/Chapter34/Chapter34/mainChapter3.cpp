#include "singlyList.h"
#include <map>
#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main()
{
	SinlyList<int> list;
	list.add(10);
	list.add(1);
	list.add(3);
	list.remove(10);
	list.print();
	return 0;
}

///*  3.23  */
//string infix2postfix(const vector<string> &s)
//{
//	MyStack<string> stack;
//	string pos;
//	string tmp;
//	for (auto i = s.begin(); i != s.end(); ++i) {
//		if (*i == "+" || *i == "-") {
//			while (stack.size() != 0) {
//				if ((tmp = stack.pop()) == "*" || tmp == "/" || tmp == "+" || tmp == "-")
//					pos += tmp;
//				else {
//					stack.push(tmp);
//					break;
//				}
//			}
//			stack.push(*i);
//		} 
//		else if (*i == "*" || *i == "/") {
//			while (stack.size() != 0) {
//				if ((tmp = stack.pop()) == "*" || tmp == "/")
//					pos += tmp;
//				else {
//					stack.push(tmp);
//					break;
//				}
//			}
//			stack.push(*i);
//		}
//		else if (*i == "(")
//			stack.push(*i);
//		else if (*i == ")") {
//			while ((tmp = stack.pop()) != "(") {
//				pos += tmp;
//			}
//		}
//		else
//			pos += *i;
//	}
//	while (stack.size() != 0) {
//		pos += stack.pop();
//	}
//	return pos;
//}

///*  3.4 Good  */
//template <typename Object>
//list<Object> intersection(const list<Object> & L1,
//	const list<Object> & L2)
//{
//	list<Object> intersect;
//	typename list<Object>::const_iterator iterL1 = L1.begin();
//	typename list<Object>::const_iterator iterL2 = L2.begin();
//	while (iterL1 != L1.end() && iterL2 != L2.end())
//	{
//		if (*iterL1 == *iterL2)
//		{
//			intersect.push_back(*iterL1);
//			iterL1++;
//			iterL2++;
//		}
//		else if (*iterL1 < *iterL2)
//			iterL1++;
//		else
//			iterL2++;
//	}
//	return intersect;
//}

///*  3.4 Bad  */
//int main()
//{
//	list<int> l1{ 3, 4, 56, 57, 67, 90, 91 };
//	list<int> l2{ 2, 3, 45, 57, 90 };
//	list<int> inter;
//	auto itr = l1.begin();
//	for (auto i = l2.begin(); i != l2.end(); ++i) {
//		while (true) {
//			if (*itr == *i) {
//				inter.push_back(*i);
//				break;
//			}
//			else if (*itr > *i && itr != l1.begin()) {
//				if (*--itr < *i) break;
//			}
//			else if (*itr < *i && itr != --l1.end()) {
//				if (*++itr > *i) break;
//			}
//			else
//				break;
//		}
//	}
//	for (auto &c : inter)
//		cout << c << ends;
//	cout << endl;
//	return 0;
//}

