#include<iostream>
#include"Queue.h"
using namespace std;
int main() {
	Queue<int> q(4);
	q.Enqueue(1);
	q.Enqueue(2);
	q.Enqueue(3);
	q.Enqueue(4);
	q.print();
	q.Enqueue(5);
	q.Dequeue();
	q.Dequeue();
	q.print();

	stlQueue();

}