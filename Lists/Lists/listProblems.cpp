#include<iostream>

using namespace std;

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
void printList(struct node* temp) {
	while (temp != NULL) {
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << endl;
}
//Reversing a list
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
	insertNodeAtFront(&head, 5);
	insertNodeAtFront(&head, 4);
	insertNodeAtFront(&head, 3);
	insertNodeAtFront(&head, 2);
	insertNodeAtFront(&head, 1);

	cout << "List before reverse: ";
	printList(head);

	reverseList(&head);

	cout << "List after reverse: ";
	printList(head);
	return 0;
}
