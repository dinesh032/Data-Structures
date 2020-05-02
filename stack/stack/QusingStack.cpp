#include<iostream>
#include<stack>
#include"stack.h"
using namespace std;
//implement a queue using stack data structure
void Dequeue(stack<int>& s1, stack<int>& s2) {
	
}
void queueUsingStacks() {
	stack<int> s1;
	stack<int> s2;
	s1.push(3);
	s1.push(2);
	s1.push(1);
	Dequeue(s1, s2);
}