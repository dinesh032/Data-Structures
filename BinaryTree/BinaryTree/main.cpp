#include<iostream>
#include<conio.h>
#include<algorithm>
#include<list>
#include<stack>
#include"binaryTree.h"
using namespace std;
extern list<int> l;

int main() {
	struct node* root = newNode(4);
	root->left = newNode(2);
	root->right = newNode(6);
	root->left->left = newNode(1);
	root->left->right = newNode(3);
	root->right->right = newNode(7);
	root->right->left = newNode(5);

	cout << "Level order traversal: ";
	printLevelOrder(root);

	binaryTreeToList(root);
	cout << endl<<"List from binary tree: ";
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
		cout << *it << ", ";

	isBST(root) == 1 ? cout<<"\nTree is binary" : cout<<"\nTree is not binary";
	//if (isBST(root)) { cout << "\nthe given tree is BST\n"; }
	//else { cout << "\nthe given tree is NOT BST\n"; }
	cin.get();
	return 0;
}