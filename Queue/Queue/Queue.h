#pragma once
template<class T>
class Queue {
	T* arr;
	int front, rear;
	int capacity;
public:
	Queue(int size);
	void Enqueue(T x);
	void Dequeue();
	bool isEmpty();
	bool isFull();
	void print();
	~Queue();
};
void stlQueue();
