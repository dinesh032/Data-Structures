#include<iostream>
#include<conio.h>
#include<vector>
#include<algorithm>
#include<iterator>

//Write a function rotate(ar[], d, n) that rotates arr[] of size n by d elements.
//Problem description: http://www.geeksforgeeks.org/array-rotation/

using namespace std;

vector<int> rotateArray(vector<int>& vec, int d, int n) {
	int temp;
	for (int i = 0; i < d; i++) {
		temp = vec[0];
		for (int j = 0; j < n-1; j++) {
			vec[j] = vec[j + 1];
		}
		vec[n-1] = temp;
	}
	return vec;
}
//C++11 rotate function usage
vector<int> rotateArrayFunc(vector<int>& vec, int d, int n) {
    rotate(vec.begin(), vec.begin()+d, vec.end());
    return vec;
}
int main() {
	int n, d;
	int input;
	cout << "Enter the no. of elements: ";
	cin >> n;
	vector<int> vec;
	cout << endl<<"Enter the "<<n<<" elements:";

	while(cin>>input && input != 9999)
		vec.push_back(input);

	cout << endl <<"Enter the rotate value:";
	cin >> d;

	cout << "The values of array before rotation: ";
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		cout << *it << ", ";

	vec = rotateArray(vec, d, n);

	cout << endl << "The values of array after " << d << " rotations: ";
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		cout << *it << ", ";

    cout<<endl<<"C++11 rotate function usage, after "<<d<<" more rotations:";
    vec = rotateArrayFunc(vec, d, n);

	cout << endl << "The values of array after " << d << " rotations: ";
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		cout << *it << ", ";
	_getch();
	return 0;
}
