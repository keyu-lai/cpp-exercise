#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <new>
#include <cctype>
#include "TextQuery.h"
#include <fstream>
#include "Employee.h"

using namespace std;

int main()
{
	Message ma("one"), mb("two"), mc("three");
	Folder fa("fa"), fb("fb");
	fa.add(ma);
	fa.add(mb);
	fa.add(mc);
	fb.add(mb);
	fb.add(mc);
	ma = mb;
	ma.output();
	fb.output();
}



