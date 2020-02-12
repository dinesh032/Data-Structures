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
//reversing a list
void reverseList(struct node** head) {
	struct node* cur = *head;
	struct node* prev = NULL;
	struct node* next;
	while (cur != NULL) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
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

	deleteNode(&head, 9);
	cout << "After deleting node 9: ";
	printList(head);

	reverseList(&head);
	cout << "List after reversing: ";
	printList(head);

	return 0;
}
