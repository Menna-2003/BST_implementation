#include<iostream>
#include "BST.h"
using namespace std;
int main() {
	BST tree;
	tree.insert(100);
	tree.insert(200);
	tree.insert(90);
	tree.insert(150);
	tree.insert(125);
	tree.insert(88);
	tree.insert(99);
	tree.insert(210);
	tree.remove(88);
	/*cout << tree.contains(150) << "\n";
	cout << tree.contains(60) << "\n";*/

	//Node* parent = tree.findParent(88);
	//cout << parent->data;

	//cout << "\n";
	
	//Node* min = tree.findMin(tree.root);
	//cout << min->data;

	tree.traverse(InOrder);
	cout << "\n";
	tree.traverse(PreOrder);
	cout << "\n";
	tree.traverse(PostOrder);

	return 0;
}