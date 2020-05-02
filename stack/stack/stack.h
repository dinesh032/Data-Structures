#pragma once

template<class T>
class Stack {
	T* arr;
	int top;
	int capacity;
public:
	Stack(int size);
	void push(T x);
	T pop();
	T peek();
	bool isEmpty();
	bool isFull();
	void print();
	~Stack();
};
void stackStl();
void queueUsingStacks();

