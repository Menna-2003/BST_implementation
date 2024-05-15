#include<iostream>
#include "BST.h"
using namespace std;
int main() {

	BST<int> tree;
	tree.insert(100);
	tree.insert(150);
	tree.insert(50);

	cout << tree.contains(150) << "\n";
	cout << tree.contains(60) << "\n";

	return 0;
}