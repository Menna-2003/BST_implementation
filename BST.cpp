#include "BST.h"
#include<iostream>
#include "assert.h"
using namespace std;
Node::Node(int val) {
	data = val;
	right = NULL;
	left = NULL;
}

BST::BST() {
	root = NULL;
}

void BST::insert(int val)
{
	assert(!contains(val));
	Node* nodetoBeInserted = new Node(val);
	if (root == NULL){
		root = nodetoBeInserted;
		cout << "Node " << val << " Added\n";
	}
	else {
		Node* temp = root;
		while (true) {
			if (val > temp->data) {
				if (temp->right == NULL) {
					temp->right = nodetoBeInserted;
					cout << "Node " << val << " Added\n";
					break;
				}
				else {
					temp = temp->right;
				}
			}
			else if (val < temp->data) {
				if (temp->left == NULL) {
					temp->left = nodetoBeInserted;
					cout << "Node " << val << " Added\n";
					break;
				}
				else {
					temp = temp->left;
				}
			}
			else
				break;
		}
	}
}

bool BST::contains(int val)
{
	Node* temp = root;
	while (temp != NULL) {
		if (temp->data == val) {
			return true;
		}
		else if (temp->data > val) {
			temp = temp->left;
		}
		else if (temp->data < val) {
			temp = temp->right;
		}
	}
	return false;
}

Node* BST::findNode(int val)
{
	Node* temp = root;
	while (temp != NULL) {
		if (temp->data == val) {
			return temp;
		}
		else if (temp->data > val) {
			temp = temp->left;
		}
		else if (temp->data < val) {
			temp = temp->right;
		}
	}
}

void BST::traverse(Order order)
{
	if (order == InOrder) {
		inOrder(root);
	}
	else if (order == PreOrder) {
		preOrder(root);
	}
	else {
		postOrder(root);
	}
}

Node* BST::findParent(int val)
{
	Node* ptr = root;
	Node* parent = NULL;
	
	while (ptr != NULL){
		if (ptr->data == val) {
			break;
		}
		parent = ptr;
		if (ptr->data > val) {
			ptr = ptr->left;
		}
		else if (ptr->data < val) {
			ptr = ptr->right;
		}
	}
	return parent;
}

Node* BST::findMin(Node* start)
{
	Node* min = start;
	while (min->left != NULL)
	{
		min = min->left;
	}
	return min;
}

void BST::remove(int val)
{
	assert(contains(val));
	Node* node = findNode(val);
	if (node->left == NULL && node->right == NULL) {
		if (node == root) {
			root = NULL;
		}
		else {
		Node* parent = findParent(val);
			if (val < parent->data) {
				parent->left = NULL;
			}
			else {
				parent->right = NULL;
			}
		}
		delete node;
	}
	else if (node->left != NULL && node->right == NULL) {
		if (node == root) {
			root = node->left;
		}
		else{
			Node* parent = findParent(val);
			if (val > parent->data) {
				parent->right = node->left;
			}
			else {
				parent->left = node->left;
			}
		}
		delete node;
	}
	else if (node->left == NULL && node->right != NULL) {
		if (node == root) {
			root = node->right;
		}
		else {
			Node* parent = findParent(val);
			if (parent->data < val) {
				parent->right = node->right;
			}
			else {
				parent->left = node->right;
			}
		}
		delete node;
	}
	else {
		Node* min = findMin(node->right);
		int x = min->data;
		remove(min->data);
		node->data = x;
	}

}

void BST::inOrder(Node* node)
{
	if (node != NULL) {
		inOrder(node->left);
		cout << node->data << " ";
		inOrder(node->right);
	}
}
void BST::preOrder(Node* node)
{
	if (node != NULL) {
		cout << node->data << " ";
		preOrder(node->left);
		preOrder(node->right);
	}
}
void BST::postOrder(Node* node)
{
	if (node != NULL) {
		postOrder(node->left);
		postOrder(node->right);
		cout << node->data << " ";
	}
}

void BST::deleteBST(Node* node)
{
	if (node == NULL)	return;
	Node* current = node;
	Node* left = node->left;
	Node* right = node->right;
	delete(current);
	deleteBST(left);
	deleteBST(right);
}

BST::~BST()
{
	deleteBST(root);
}