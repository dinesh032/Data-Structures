#include<iostream>
#include<queue>
using namespace std;
void circularQueue();
void print(queue<int> q) {
	cout << "\ncontents of stack are: ";
	while (!q.empty()) {
		cout << q.front() << "->";
		q.pop();
	}
}
void popStack(queue<int>& origQ, queue<int>& copyQ) {
	while (origQ.size() != 1) {
		copyQ.push(origQ.front());	//push elements into q2 except the last/rear element
		origQ.pop();
	}
	origQ.pop();
	//swap 2 queues
	queue<int> Q = origQ;
	origQ = copyQ;
	copyQ = Q;
}
int main() {
	queue<int> q1;
	queue<int> q2;
	q1.push(3);
	q1.push(2);
	q1.push(1);
	cout << endl << q1.size();
	print(q1);

	popStack(q1, q2);
	print(q1);
	popStack(q1, q2);
	print(q1);
	popStack(q1, q2);
	print(q1);

	cout << "\nCIRCULAR QUEUE-----";
	circularQueue();
}