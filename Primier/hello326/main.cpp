#include <iostream>
#include <string>
#include <vector>
#include "StrVec.h"
using namespace std;

int main()
{
	StrVec str;
	str.push_back("adf");
	str.push_back("sdfd");
	for (auto i = str.begin(); i != str.end(); ++i)
		cout << *i << ends;
	cout << endl;
	return 0;
}