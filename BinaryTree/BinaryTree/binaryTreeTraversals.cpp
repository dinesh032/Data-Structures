#include<iostream>
#include<conio.h>
#include<algorithm>
#include<list>
#include<stack>
using namespace std;
list<int> l;
// Level order traversal http://www.geeksforgeeks.org/level-order-tree-traversal/

struct node
{
	int data;
	struct node* left, *right;
};
struct node* newNode(int data) {
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = node->right = NULL;
	return node;
}
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

	//converting binary to tree to double linked list(list in C++11)
	binaryTreeToList(root);
	cout << endl<<"List from binary tree: ";
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
		cout << *it << ", ";

	_getch();
	return 0;
}