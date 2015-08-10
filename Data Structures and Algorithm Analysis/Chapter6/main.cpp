#include <iostream>
#include "LeftistHeaps.h"

using namespace std;

int main()
{
	LeftistHeaps<int> heap1,heap2;

	heap1.insert(13);
	heap1.insert(21);
	heap1.insert(9);
	heap1.insert(24);
	heap1.insert(31);
	heap1.insert(23);
	heap2.insert(68);
	heap2.insert(65);
	heap2.insert(43);
	heap2.insert(3);
	heap2.insert(14);
	heap1.merge(heap2);
	heap1.print();
	heap2 = heap1;
	cout << endl;
	heap2.print();
	return 0;
}

