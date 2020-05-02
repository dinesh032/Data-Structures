#include<iostream>
#include"listhdr.h"
using namespace std;

void printList(struct node* temp) {
	while (temp != NULL) {
		cout << temp->data << "-->";
		temp = temp->next;
	}
	cout << endl;
}
int countNodes(struct node* temp) {
	int count = 0;
	while (temp != NULL) {
		count++;
		temp = temp->next;
	}
	return count;
}
//split the list in 2 halves
void frontBackSplit(struct node** head) {
	struct node* front = NULL;
	struct node* back = NULL;
	struct node* slow = *head;
	struct node* fast = *head;
	if (slow == NULL || slow->next == NULL) {	 //0 or 1 nodes, no need of split
		front = *head;
	}
	while (fast->next != NULL) {	//after end of this, slow is at midway and fast at the end of list
		fast = fast->next;
		if (fast->next != NULL) {
			slow = slow->next;
			fast = fast->next;
		}
	}
	//now arrange the nodes to get 2 split lists
	front = *head;
	back = slow->next;
	slow->next = NULL;
	cout << "The split list are, front list: ";
	printList(front);
	cout << "back list: ";
	printList(back);
}
//reversing a list
void reverseList(struct node** head) {
	struct node* cur = *head;
	struct node* prev = NULL;
	struct node* temp;
	while (cur != NULL) {
		temp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = temp;
	}
	*head = prev;
}