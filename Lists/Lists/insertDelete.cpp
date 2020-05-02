#include<iostream>
#include"listhdr.h"
using namespace std;
//Inserting at the front of list
void insertNodeAtFront(struct node** head, int data) {
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}
//Inserting at the end of list
void insertNodeAtBack(struct node** head, int data) {
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	struct node* current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = newNode;
	newNode->next = NULL;
}
//Insert node after n iterations
void insertNodeAfter(struct node** head, int n, int data) {
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	struct node* current = *head;
	struct node* prev = NULL;
	int count = 0;
	while (current != NULL && count != n) {
		count++;
		prev = current;
		current = current->next;
	}
	if (current == NULL)
		cout << n << " bigger than size of list" << endl;
	if (count == n) {
		newNode->next = prev->next;
		prev->next = newNode;
	}
}
//insert in sorted order
void sortedInsert(struct node** head, int data) {
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	struct node* current = *head;
	struct node* prev = NULL;
	newNode->data = data;
	if (*head == NULL) {	//first insert in the list
		newNode->next = NULL;
		*head = newNode;
	}
	while (current != NULL && current->data < data) {
		prev = current;
		current = current->next;
	}
	if (prev == NULL) {	//that means, insert at start of list
		newNode->next = current;
		*head = newNode;
	}
	else {		//insert in between or end condition
		prev->next = newNode;
		newNode->next = current;
	}
}
//Delete a given node in list
void deleteNode(struct node** head, int n) {
	struct node* current = *head;
	struct node* prev = NULL;
	if (current != NULL && current->data == n) {  //check if first node to be deleted
		*head = current->next;
		free(current);
		return;
	}
	while (current != NULL && current->data != n) {  //traverse to right node
		prev = current;
		current = current->next;
	}
	if (current == NULL) {       //if NO node found to be deleted
		cout << "node " << n << " NOT found" << endl;
		return;
	}
	if (current->data == n) {    //delete the node
		prev->next = current->next;
		free(current);
		return;
	}
}
//delete whole list 
void deleteList(struct node** head) {
	struct node* current = *head;
	struct node* next;
	while (current != NULL) {
		next = current->next;	//save next node
		free(current);			//delete current node
		current = next;			//assign the next node to current for delete again
		printList(current);
	}
	cout << "deleted the whole list.";
	*head = NULL;
}