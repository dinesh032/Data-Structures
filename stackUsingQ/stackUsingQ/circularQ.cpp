#include<iostream>
using namespace std;
struct queue {
	int* arr;
	int front, rear;
	int size;
	void initialize(int s);
	void Enqueue(int x);
	int Dequeue();
	bool isEmpty();
	bool isFull();
	void printQ();
};
void queue::initialize(int s) {
	size = s;
	arr = new int[size];
	front = rear = 0;
}
void queue::Enqueue(int x) {
	if ((front == 0 && rear == size) || rear == front - 1) {
		cout << "\nqueue is FULL";
		return;
	}
	if (rear == size) {
		rear = 0;
		arr[rear++] = x;
	}
	else {
		arr[rear++] = x;
	}
}
int queue::Dequeue() {
	if (front == rear) {
		cout << "\nqueue is EMPTY";
		front = rear = 0;
	}
	if (front == size)
		front = 0;
	front++;
	return front;
}
bool queue::isEmpty() {
	return true;
}
bool queue::isFull() {
	return true;
}
void queue::printQ() {
	int j = front;
	cout << "\ncontents of circular queue are: ";
	if (rear > front) {
		for (int i = front; i < rear; i++) {
			cout << arr[i] << "->";
		}
	}
	else {
		for (int i = front; i < size; i++)
			cout << arr[i] << "->";
		for (int i = 0; i < rear; i++)
			cout << arr[i] << "->";
	}
}
void circularQueue() {
	struct queue Q;
	Q.initialize(5);
	Q.Enqueue(1);
	Q.Enqueue(3);
	Q.Enqueue(6);
	Q.Enqueue(7);
	Q.Enqueue(9);
	Q.Enqueue(11);
	Q.printQ();
	Q.Dequeue();
	Q.printQ();
	Q.Enqueue(11);	//3->6->7->9->11
	Q.Dequeue();
	Q.Dequeue(); 
	Q.printQ();
}
