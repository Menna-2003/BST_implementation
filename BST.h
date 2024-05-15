#pragma once
enum Order {
	InOrder = 0, PreOrder = 1, PostOrder = 2
};
class Node
{
public:
	int data;
	Node* right;
	Node* left;
	Node(int val);
};

class BST
{
public:
	Node* root;
	BST();
	~BST();
	void insert(int val);
	bool contains(int val);
	Node* findNode(int val);
	void traverse(Order order);
	Node* findParent(int val);
	Node* findMin(Node* start);
	void remove(int val);
private:
	void inOrder(Node* node);
	void preOrder(Node* node);
	void postOrder(Node* node);
	void deleteBST(Node* node);
};

