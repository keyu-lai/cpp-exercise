#ifndef MY_STACK_H
#define MY_STACK_H

#include "myList.h"

template<typename T>
class MyStack
{
private:
	MyList<T> stack;
	size_t theSize;
public:
	MyStack():theSize(0) {}
	MyStack(const MyStack &s): stack(s.stack), theSize(s.theSize) {}
	~MyStack() {}
	MyStack& operator=(const MyStack &s) {
		if (this != &s) {
			stack = s.stack;
			theSize = s.theSize;
		}
	}
	size_t size() { return theSize; }
	void push(const T &t) { 
		++theSize;
		stack.push_back(t); 
	}
	T pop() {
		--theSize;
		T tmp = *(--stack.end());
		stack.pop_back();
		return tmp;
	}
};

#endif