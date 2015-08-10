#include <iostream>
#include <algorithm>
#include "StrVec.h"

using namespace std;

void StrVec::free()
{
	for_each(elements, first_free, [this](string &s) {alloc.destroy(&s);});
	alloc.deallocate(elements,cap - elements);
	cap = first_free = elements = nullptr;
}

void StrVec::chk_n_alloc()
{
	if (first_free == cap)
	{
		auto size = cap - elements, n = (size) ? 2 * size : 1;
		auto tmp = alloc.allocate(n);
		for (auto i = elements; i != first_free; i++)
			alloc.construct(tmp++, std::move(*i));
		free();
		elements = tmp - size;
		first_free = tmp;
		cap = elements + n;
	}
}

void StrVec::push_back(const string &s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

StrVec::StrVec(const StrVec& vec)
{
	for (auto i = vec.elements; i != vec.first_free; ++i)
		push_back(*i);			
}

StrVec& StrVec::operator=(const StrVec &vec)
{
	if (this != &vec)
	{
		free();
		for (auto i = vec.elements; i != vec.first_free; ++i)
			push_back(*i);
	}
	return *this;
}

StrVec::~StrVec()
{
	free();
}

void StrVec::output(void)
{
	for (auto i = elements; i != first_free; ++i)
		cout << *i << ends;
	cout << endl;
}

void StrVec::reserve(size_t n)
{
	if (capacity() < n)
	{
		auto siz = size();
		auto tmp = alloc.allocate(n);
		for (auto i = elements; i != first_free; i++)
			alloc.construct(tmp++, std::move(*i));
		free();
		elements = tmp - siz;
		first_free = tmp;
		cap = elements + n;
	}
}

void StrVec::resize(size_t num)
{
	if (capacity() < num)
	{
		auto siz = size(), n = 2 * num;
		auto tmp = alloc.allocate(n), mark = tmp + num;
		for (auto i = elements; i != first_free; i++)
			alloc.construct(tmp++, std::move(*i));
		while (tmp != mark)
			alloc.construct(tmp++);
		free();
		elements = mark - num;
		first_free = mark;
		cap = elements + n;
	}
	else if (num > size())
	{
		auto mark = elements + num;
		for (auto i = first_free; i != mark; i++)
			alloc.construct(first_free++);
	}
}

StrVec::StrVec(StrVec&& s): elements(s.elements), first_free(s.first_free), cap(s.cap)
{
	s.elements = s.first_free = s.cap = nullptr;
}

StrVec& StrVec::operator = (StrVec&& s)
{
	if (this != &s)
	{
		free();
		elements = s.elements;
		first_free = s.first_free; 
		cap = s.cap;
		s.elements = s.first_free = s.cap = nullptr;
	}
	return *this;
}

