#ifndef STRVEC_H_
#define STRVEC_H_

#include <string>
#include <memory>

class StrVec
{
private:
	std::allocator<std::string> alloc;
	std::string *elements;
	std::string *first_free;
	std::string *cap;
	void chk_n_alloc();
	void free();
public:
	StrVec(): elements(nullptr),first_free(nullptr),cap(nullptr) { }
	StrVec(const StrVec&);
	StrVec& operator=(const StrVec&);
	StrVec(StrVec&&);
	StrVec& operator=(StrVec&&);
	~StrVec();
	void push_back(const std::string&);
	std::string* begin() const { return elements; }
	std::string* end() const { return first_free; }
	std::size_t size() const { return (first_free - elements); }
	std::size_t capacity() const { return (cap - elements); }
	void output(void);
	void reserve(std::size_t);
	void resize(std::size_t);
};

#endif