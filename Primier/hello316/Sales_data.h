# ifndef SALES_DATA_H_
# define SALES_DATA_H_

#include <string>

class Sales_data
{
	friend Sales_data add(const Sales_data &a, const Sales_data &b);
	friend std::ostream &print(std::ostream &os, const Sales_data &in);
	friend std::istream &read(std::istream &is, Sales_data &in);
public:
	Sales_data() = default;
	Sales_data(const std::string &s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p) { }
	Sales_data(const std::string &s) : Sales_data(s,0,0.0){}
	Sales_data(std::istream is);
	std::string isbn() const { return bookNo; }
	Sales_data &combine(const Sales_data & in);
private:
	double avy_price() const
	{ return (units_sold > 0 ? revenue / units_sold : 0); }
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

Sales_data add(const Sales_data &a, const Sales_data &b);
std::ostream &print(std::ostream &os, const Sales_data &in);
std::istream &read(std::istream &is, Sales_data &in);

# endif 
