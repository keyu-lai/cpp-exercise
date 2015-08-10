#include "QueryResult.h"


std::ostream&
operator <<(std::ostream &os, const QueryResult &qr)
{
	os << qr.sought << " occurs " << qr.sp_lines->size() << " "
		<< "times" << "\n";

	//! print each line in which the word appears
	for (auto &index : *qr.sp_lines)
	{
		os << "\t(line " << index + 1 << ") ";
		os << *(qr.file.begin() + index) << "\n";
	}
	return os;

}