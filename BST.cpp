#include "BST.h"
#include<iostream>
using namespace std;
template<class T>
Node<T>::Node(T val) {
	data = val;
	right = NULL;
	left = NULL;
}
template<class T>
BST<T>::BST() {
	root = NULL;
}
template<class T>
void BST<T>::insert(T val)
{
	if (root == NULL){
		root = new Node<T>(val);
		return;
	}
	Node<T>* ptr = NULL;
	Node<T>* parentptr = root;
	while (ptr != NULL) {
		if (val > ptr->data) {
			parentptr = ptr;
			ptr = ptr->right;
		}
		else if (val < ptr->data) {
			ptr = ptr->left;
		}
		else {
			return;
		}
	}
	if (val > parentptr->data)
		parentptr->right = new Node<T>(val);
	else
		parentptr->left = new Node<T>(val);

}
template<class T>
bool BST<T>::contains(T val)
{
	Node<T>* temp = root;
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
