#include<iostream>
#include"binaryTree.h"
#include<list>
using namespace std;
list<int> l;

int height(struct node* node) {
	if (node == NULL)
		return 0;
	else {
		int lheight = height(node->left);
		int rheight = height(node->right);
		if (lheight > rheight)
			return lheight + 1;
		else
			return rheight + 1;
	}
}
// Level order traversal http://www.geeksforgeeks.org/level-order-tree-traversal/
void printGivenLevel(struct node* root, int level) {
	if (root == NULL)
		return;
	if (level == 1)
		cout << root->data << " ";
	else if (level > 1) {
		printGivenLevel(root->left, level - 1);
		printGivenLevel(root->right, level - 1);
	}
}
void printLevelOrder(struct node* root) {
	int h = height(root);
	for (int i = 0; i < h; i++)
		printGivenLevel(root, i + 1);
}
//binary tree to double linked list
void binaryTreeToList(struct node* root) {
	if (root == NULL)
		return;
	binaryTreeToList(root->left);
	l.push_back(root->data);
	binaryTreeToList(root->right);
}
bool isBST(struct node* root) {		//check if the given tree is a BST
	if (root == NULL) return true;
	if (root->left != NULL && root->left->data > root->data) return false;
	if (root->right != NULL && root->right->data < root->data) return false;
	if (!isBST(root->left) || !isBST(root->right)) return false;
	return true;
}
