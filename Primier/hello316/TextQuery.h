#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <fstream>
#include <memory>


class TextQuery
{
public:
	TextQuery(void) = default;
	TextQuery(std::ifstream &fin) ;
	std::shared_ptr<std::set<int>> find(const std::string str) const;
private:
	std::vector<std::string>  text;
};

#endif