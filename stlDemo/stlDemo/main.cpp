#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#pragma pack(1)
using namespace std;

void printVector(const vector<int>& V) {
	for (auto i = V.begin(); i != V.end(); i++)
		cout << *i << ", ";
	cout << endl;
}
void vectorDemo() {
	vector<int> V;
	V.push_back(9);
	V.push_back(5);
	V.push_back(12);
	V.push_back(3);
	V.push_back(18);
	V.push_back(1);
	cout << "--------vectors-----------" << endl;
	printVector(V);		//9,5,12,3,18,1

	sort(V.begin(), V.end());	//1,3,5,9,12,18

	V.push_back(100);
	V.push_back(100);
	V.push_back(100);
	V.push_back(100);
	V.push_back(123);
	printVector(V);		//1,3,5,9,12,18,100,100,100,100,123

	vector<int>::iterator it1 = lower_bound(V.begin(), V.end(), 100);	//>= 100..returns 1st iterator to 100
	vector<int>::iterator it2 = upper_bound(V.begin(), V.end(), 100);	// > 100..returns 1st entry >100
	cout << "lower bound: " << *it1 << ", upper bound: " << *it2 << endl;
	cout << "No. of 100s: " << it2 - it1;	//count of a number by using lower bound & upper bound
}
void setDemo() {
	multiset<int> S;
	S.insert(1);
	S.insert(7);
	S.insert(2);
	S.insert(5);
	S.insert(23);
	S.insert(2);
	S.erase(7);
	cout << "\n\n--------sets---------\n";
	for (auto i : S)
		cout << i << ", ";
	auto it = S.find(23);
	if (it != S.end()) {	//returns end if NOT found
		cout << endl << "element " << *it << " present\n";
	}
	else {
		cout << endl << "element NOT present";
	}
}
void mapDemo() {
	map<char, int> M;
	string str = "dinesh kumar biradar";
	cout << "\n-------map--------\n";
	for (auto i : str)
		M[i]++;
	cout << "no. of a's: " << M['a'] << ", no. of i's: " << M['i'] << " & no. of z's: " << M['z'] << endl;
}
void findInterval() {

}
struct s {
	int a;
	char b;
};
int main() {
	//vectorDemo();
	setDemo();
	//mapDemo();
	//findInterval();

	return 0;

}