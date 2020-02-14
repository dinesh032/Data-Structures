#include<iostream>

using namespace std;

//Declare the list struct
struct node {
	int data;
	struct node* next;
};
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
//split the list in 2 halves
void frontBackSplit(struct node** head){
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
int main() {
	struct node* head = NULL;
	insertNodeAtFront(&head, 9);	//insert at front
	insertNodeAtFront(&head, 8);
	insertNodeAtFront(&head, 6);
	insertNodeAtFront(&head, 5);
	insertNodeAtFront(&head, 4);
	insertNodeAtFront(&head, 3);
	insertNodeAtBack(&head, 10);	//insert at back
	insertNodeAtBack(&head, 11);

	printList(head);

	insertNodeAfter(&head, 4, 7);	//insert after a specific node

	cout << endl << "List after insertions: ";
	printList(head);

	deleteNode(&head, 9);	//delete a specified node
	cout << "After deleting node 9: ";
	printList(head);

	reverseList(&head);
	cout << "List after reversing: ";
	printList(head);
	cout << endl << "No. of nodes in list: " << countNodes(head);	//count function

	cout << endl << "delete the whole list: ";
	deleteList(&head);

	cout << endl << "sorted insert: ";

	sortedInsert(&head, 5);
	sortedInsert(&head, 3);
	sortedInsert(&head, 4);
	sortedInsert(&head, 9);
	sortedInsert(&head, 8);
	sortedInsert(&head, 7);
	printList(head);

	frontBackSplit(&head);
	return 0;
}
