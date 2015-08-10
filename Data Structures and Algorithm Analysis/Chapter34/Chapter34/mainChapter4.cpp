#include "SplayTree.h"
#include <iostream>

using namespace std;

int main()
{
	SplayTree<int> tree;
	tree.insert(1);
	tree.insert(2);
	tree.insert(3);
	tree.insert(4);
	tree.insert(5);
	tree.insert(6);
	tree.insert(7);
	tree.insert(16);
	tree.insert(15);
	tree.insert(14);
	tree.insert(13);
	tree.remove(13);
	tree.remove(3);
	cout << tree.findKth(7) << endl;
	cout << tree.contains(13) << endl;
	cout << tree.contains(14) << endl;
	cout << tree.top() << endl;
	tree.printTree();
	return 0;
}