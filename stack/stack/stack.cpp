#include<iostream>
#include"stack.h"
using namespace std;
template class Stack<int>; //very important, this lets have the member functions for int datatype. If not defined..it will lead to linker error as there are no member functions for int, there are only generic member functions
template class Stack<string>;	//can now create objects of only int and string type 

template<class T>
Stack<T>::Stack(int size) {
	arr = new T[size];	//T important here, instead of int
	top = -1;
	capacity = size;
}
template<class T>
Stack<T>::~Stack() {
	delete[] arr;
}
template<class T>
void Stack<T>::push(T x) {
	if (!isFull()) {
		arr[++top] = x;
	}
	else
		cout << "\ncan't push " << x << " stack is FULL";
}
template<class T>
T Stack<T>::pop() {
	if (!isEmpty()) {
		return arr[top--];
	}
	else
		cout << "\ncan't pop, stack is EMPTY";
}
template<class T>
bool Stack<T>::isFull() {
	if (top == capacity - 1)
		return true;
	else
		return false;
}
template<class T>
bool Stack<T>::isEmpty() {
	bool f = top == -1 ? true : false;
	return f;
}
template<class T>
T Stack<T>::peek() {
	if (!isEmpty())
		return arr[top];
}
template<class T>
void Stack<T>::print() {
	int i = 0;
	cout << "\nstack contents are: ";
	while (i <= top && top != -1) {
		cout << arr[i++] << ", ";
	}
}