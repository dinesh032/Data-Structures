#include<iostream>
#include"listhdr.h"
using namespace std;

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
