#pragma once
template<class T>
class Node
{
public:
	T data;
	Node<T>* right;
	Node<T>* left;
	Node(T);
};
template<class T>
class BST
{
private:
	Node<T>* root;
public:
	BST();
	void insert(T val);
	bool contains(T val);
};

