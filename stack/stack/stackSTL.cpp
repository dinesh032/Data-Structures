#include<stack>
#include<iostream>

using namespace std;
void printStack(stack<int> stls) {
	cout << "\ncontents of stl stack: ";
	while (!stls.empty()) {
		cout << stls.top() << ", ";
		stls.pop();
	}
}
void stackStl() {
	cout << endl << "\nSTL STACK methods";
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.pop();
	//printing the stack in STL
	printStack(s);
}