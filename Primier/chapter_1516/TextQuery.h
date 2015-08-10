#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <map>
#include <set>
#include <string>
#include <memory>
#include <fstream>
#include <vector>

class QueryResult;

class TextQuery
{
public:
	typedef std::vector<std::string>::size_type line_no;
	TextQuery(std::ifstream& fin);
	QueryResult query(const std::string&) const;
private:
	std::vector<std::string> file;
	std::map<std::string,
		std::shared_ptr<std::set<line_no>>> wordMap;

};


#endif // TEXTQUERY_H