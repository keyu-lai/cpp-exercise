#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

template<typename T>
T myfind(const T &begin, const T &end, typename const T::value_type &value)
{
	auto i = begin;
	for (; i != end; ++i){
		if (value == *i)
			break;
	}
	return i;
}

int main()
{
	vector<int> vec{ 1, 34, 54, 23, 56 };
	cout << *(myfind(vec.begin(), vec.end(), 54)) << endl;
	vector<int>::iterator::value_type a = 10;
	return 0;
}