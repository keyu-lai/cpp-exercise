#include "Sales_data.h"

Sales_data & Sales_data::combine(const Sales_data & in)
{
	if (bookNo == in.bookNo)
	{
		revenue += in.revenue;
		units_sold += in.units_sold;
	}
	return *this;
}

Sales_data add(const Sales_data &a, const Sales_data &b)
{
	Sales_data out;
	if (a.bookNo == b.bookNo)
	{
		out.bookNo = a.bookNo;
		out.revenue = a.revenue + b.revenue;
		out.units_sold = a.units_sold + b.units_sold;
	}
	return out;
}

std::ostream &print(std::ostream &os, const Sales_data &in)
{
	os << in.bookNo << ": " << in.units_sold << ' ' << in.revenue;
	return os;
}

std::istream &read(std::istream &is, Sales_data &in)
{
	is >> in.bookNo >> in.units_sold >> in.revenue;
	return is;
}