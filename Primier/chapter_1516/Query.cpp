#include "Query.h"
#include <memory>
#include <set>
#include <algorithm>
#include <iterator>

QueryResult OrQuery::eval(const TextQuery &text) const
{
	auto right = rhs.eval(text), left = rhs.eval(text);
	auto ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());
	ret_lines->insert(right.begin(), right.end());
	return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult AndQuery::eval(const TextQuery &text) const
{
	auto right = rhs.eval(text), left = rhs.eval(text);
	auto ret_lines = std::make_shared<std::set<line_no>>();
	std::set_intersection(left.begin(), left.end(),
		right.begin(), right.end(),
		std::inserter(*ret_lines, ret_lines->begin()));
	return QueryResult(rep(), ret_lines, left.get_file());
}



QueryResult NotQuery::eval(const TextQuery &text) const
{
	//! virtual call to eval through the Query operand
	QueryResult result = query.eval(text);

	//! start out with an empty result set
	std::shared_ptr<std::set<line_no>>
		ret_lines = std::make_shared<std::set<line_no>>();

	std::set<TextQuery::line_no>::iterator
		begin = result.begin(),
		end = result.end();

	std::vector<std::string>::size_type sz = result.get_file().size();

	for (std::size_t n = 0; n != sz; ++n)
	{
		if (begin == end || *begin != n)
			ret_lines->insert(n);
		else if (begin != end)
			++begin;
	}

	return QueryResult(rep(), ret_lines, result.get_file());
}



