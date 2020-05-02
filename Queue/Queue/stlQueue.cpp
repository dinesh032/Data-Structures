#include<iostream>
#include<queue>
#include"Queue.h"
using namespace std;
void printQueue(queue<float> q) {
	cout << endl << "contents of stl queue: ";
	while (!q.empty()) {
		cout << q.front() << ", ";
		q.pop();
	}
}
void stlQueue() {
	queue<float> qstl;
	qstl.push(2.3);
	qstl.push(4.7);
	qstl.push(3.1);
	qstl.push(2.9);
	printQueue(qstl);
	qstl.pop();
	qstl.pop();
	printQueue(qstl);
}