#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include <iostream>
#include <memory>
#include <set>
#include <vector>
#include <string>
#include "TextQuery.h"

class QueryResult
{
	friend std::ostream& operator<<(std::ostream&, const QueryResult&);

public:
	//! constructor
	QueryResult(std::string s,
		std::shared_ptr<std::set<TextQuery::line_no>> sp_l,
		std::vector<std::string> f) :
		sought(s), sp_lines(sp_l), file(f) { }

	//! added for ex12.33
	//! ? Think about wether the "const"s here are expected.
	const std::vector<std::string>& get_file() const{ return file; }

	std::set<TextQuery::line_no>::iterator
		begin() { return sp_lines->begin(); }

	std::set<TextQuery::line_no>::iterator
		end()   { return sp_lines->end(); }



private:
	//! three data members
	std::string sought;
	std::shared_ptr<std::set<TextQuery::line_no>> sp_lines;
	std::vector<std::string> file;

};

#endif // QUERYRESULT_H