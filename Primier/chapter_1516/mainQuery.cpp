#include "Query.h"
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <fstream>

using namespace std;


int main()
{
	Query q=Query("long")&Query("Despite");
	ifstream fin;
	fin.open("good.txt");
	TextQuery txt(fin);	
	cout << q.eval(txt);
	return 0;
}