#pragma once
struct node
{
	int data;
	struct node* left, * right;
};
struct node* newNode(int data);
int height(struct node* node);
void printGivenLevel(struct node* root, int level);
void printLevelOrder(struct node* root);
void binaryTreeToList(struct node* root);
bool isBST(struct node* root);
