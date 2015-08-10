#include "TextQuery.h"
#include <memory>
#include <sstream>

using namespace std;

TextQuery::TextQuery(ifstream &fin) 
{
	string str;
	while (getline(fin, str))
		text.push_back(str);
}

shared_ptr<set<int>> TextQuery::find(const string str) const
{
	shared_ptr<set<int>> ptr(new set<int>);
	cout << text.size() << endl;
	for (size_t i = 0; i < text.size(); i++)
	{
		istringstream in(text[i]);
		string tmp;
		while (in >> tmp)
			if (tmp == str)
			{
				ptr->insert(i + 1);
			}
	}
	return ptr;
}