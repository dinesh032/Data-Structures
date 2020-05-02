#include<iostream>
#include"Queue.h"
using namespace std;

template class Queue<int>;
template<class T>
Queue<T>::Queue(int size) {
	arr = new T[size];
	front = rear = 0;
	capacity = size - 1;
}
template<class T>
void Queue<T>::Enqueue(T x) {
	if (!isFull()) {
		arr[rear++] = x;
	}
	else
		cout << "\nQueue is FULL";
}
template<class T>
void Queue<T>::Dequeue() {
	if (!isEmpty()) {
		for (int i = front; i < rear; i++) {
			arr[i] = arr[i + 1];
		}
		rear--;
	}
	else
		cout << "\nQueue is EMPTY";
}
template<class T>
bool Queue<T>::isEmpty() {
	if (front == rear) return true;
	else return false;
}
template<class T>
bool Queue<T>::isFull() {
	if (rear == capacity+1) return true;
	else return false;
}
template<class T>
void Queue<T>::print() {
	cout << "\ncontents of Queue are: ";
	for (int i = front; i < rear; i++)
		cout << arr[i] << ", ";
}
template<class T>
Queue<T>::~Queue() {
	delete[] arr;
}