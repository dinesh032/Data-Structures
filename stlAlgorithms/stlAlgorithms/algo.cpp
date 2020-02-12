#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void nonModifyAlgs() {
	vector<int> V = {1,3,7,9};
	cout << "Vector V:";
	for (auto i: V)
		cout << i << ", ";
	cout << endl;
	if (all_of(V.begin(), V.end(), [](int i) {return i % 2; })) //checking if all_of V are odd numbers
		cout << "All are odd numbers in V" << endl;
	else
		cout << "All of V is not odd numbers" << endl;

	if (any_of(V.begin(), V.end(), [](int i) {return !(i % 2); })) //checking for atleast 1 even number, any_of
		cout << endl << "there's atleast 1 even number in V" << endl;
	else
		cout << "there are no even numbers in V" << endl;
	cout << "looking for 7..";
	if (binary_search(V.begin(), V.end(), 7))	//binary search alg.
		cout << "found"; else cout << "not found" << endl;

	int n = count(V.begin(), V.end(), 3);	//counts the no. of 3's in V
	cout << endl << "No. of 3's: " << n << endl;
	n = count_if(V.begin(), V.end(), [](int i) {return i % 2; });	//returns the no. of odd numbers
	cout << "No. of odd numbers in V: " << n << endl;

	auto i = find(V.begin(), V.end(), 8);	//find alg to find the entry
	if (i != V.end())
		cout << "element " << *i << " found in vector V" << endl;
	else
		cout << "element not found" << endl;
	i = find_if(V.begin(), V.end(), [](int i) {return !(i % 2); });	//find with conditions, returns the 1st even number in V
	if (i != V.end())
		cout << "the first even element in V: " << *i << endl;
	else
		cout << "no even elements in V" << endl;
}
void modifyAlgs() {
	vector<int> V = {5,8,2,4,3,0,8};
	sort(V.begin(), V.end());	//sort function
	cout << "sorted vector V: ";
	for (auto i : V) {
		cout << i << ", ";
	} cout << endl;
	if (is_sorted(V.begin(), V.end()))	//check if sorted V
		cout << "V is sorted" << endl;
	else
		cout << "V not sorted" << endl;
	auto itr = lower_bound(V.begin(), V.end(), 12);	//lower_bound
	if (itr != V.end())
		cout << "lower_bound: " << *itr << endl;
	else
		cout << "no lower bound" << endl;
	auto n = equal_range(V.begin(), V.end(), 4);	//lower and upper bound
	cout << "lower bound of 4: "<<*n.first << " & upper bound: " << *n.second << endl;
	
	vector<int> V1 = { 1,2,3,8,11 };
	for (auto j : V1) {
		cout << j << ", ";
	} cout << endl;
	vector<int> V2(20);
	auto it = set_union(V.begin(),V.end(), V1.begin(),V1.end(), V2.begin()); //union of 2 vectors
	V2.resize(it - V2.begin());
	cout << "union of V and V1: ";
	for (auto j : V2) {
		cout << j << ", ";
	} cout << endl;
	//V2.clear();
	it = set_intersection(V.begin(), V.end(), V1.begin(), V1.end(), V2.begin());	//intersection of 2 vectors
	V2.resize(it - V2.begin());
	cout << "intersection of V and V1: ";
	for (auto j : V2) {
		cout << j << ", ";
	} cout << endl;
}
int main() {
	//nonModifyAlgs();
	modifyAlgs();
	return 0;
}