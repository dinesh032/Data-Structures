#include<iostream>
#include<conio.h>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	vector<int> vec = { 12, 11 , 13, 5, 6, 7 };
	cout << "Vector before heap sort: ";
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		cout << *it<<", ";

	make_heap(vec.begin(), vec.end());
	cout << endl<< "Vector after make_heap: ";
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		cout << *it << ", ";

	sort_heap(vec.begin(), vec.end());
	cout << endl << "Vector after sort_heap: ";
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		cout << *it << ", ";

	_getch();
	return 0;
}