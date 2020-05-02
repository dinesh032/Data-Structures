#include<iostream>
#include<stack>
using namespace std;

void print(stack<int> s) {
	cout << "\ncontents of Q are: ";
	while (!s.empty()) {
		cout << s.top() << "-->";
		s.pop();
	}
}
void Enqueue(stack<int>& s1, int data) {
	s1.push(data);
}
stack<int>& Dequeue(stack<int>& s1, stack<int>& s2) {
	int x;
	while (!s1.empty()) {
		x = s1.top();
		s2.push(x);
		s1.pop();
	}
	s2.pop();
	while (!s2.empty()) {
		s1.push(s2.top());
		s2.pop();
	}
	return s1;
}
int DequeueUsingOneStack(stack<int>& s1) {
	int element = s1.top();		//element stores the value and returns these, push them into stack
	s1.pop();
	if (s1.empty())
		return element;
	int s = DequeueUsingOneStack(s1);	//keep calling until empty
	s1.push(element);	//pushes everything except the dequeued item
	return s;		//this keeps returning the dequeued item
}
int main() {
	stack<int> s1;
	stack<int> s2;
	Enqueue(s1, 3);
	Enqueue(s1, 2);
	Enqueue(s1, 1);
	print(s1);

	s1 = Dequeue(s1, s2);
	print(s1);
	s1 = Dequeue(s1, s2);
	print(s1);
	s1 = Dequeue(s1, s2);
	print(s1);

	//the above method uses 2 stacks, below one using 1 stack..use recursion
	cout << "\n\nUSING ONLY 1 STACK";
	Enqueue(s1, 3);
	Enqueue(s1, 2);
	Enqueue(s1, 1);
	print(s1);
	cout << "\nDequeued item is: " << DequeueUsingOneStack(s1);
	print(s1);
	cout << "\nDequeued item is: " << DequeueUsingOneStack(s1);
	print(s1);
	cout << "\nDequeued item is: " << DequeueUsingOneStack(s1);
	print(s1);
}