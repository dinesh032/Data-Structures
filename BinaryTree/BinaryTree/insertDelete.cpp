#include<iostream>
#include"binaryTree.h"
using namespace std;

struct node* newNode(int data) {
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->left = node->right = nullptr;
	node->data = data;
	return node;
}