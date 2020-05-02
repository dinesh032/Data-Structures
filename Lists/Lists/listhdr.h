#pragma once
struct node {
	int data;
	struct node* next;
};
void insertNodeAtFront(struct node** head, int data);
void insertNodeAtBack(struct node** head, int data);
void insertNodeAfter(struct node** head, int n, int data);
void sortedInsert(struct node** head, int data);
void deleteNode(struct node** head, int n);
void deleteList(struct node** head);
void printList(struct node* temp);
int countNodes(struct node* temp);
void frontBackSplit(struct node** head);
void reverseList(struct node** head);
