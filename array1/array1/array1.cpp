#include<iostream>
#include<vector>
#include<unordered_map>
#include"array.h"
using namespace std;
void evenNumbersFirst() {
	vector<int> V = { 1,2,5,7,6,8,9 };
	//vector<int> subA(V.begin(), V.end() - 2);
	int first = 0, last = V.size() - 1;
	while (first < last) {
		if (V[first] % 2 == 0)
			first++;
		else {
			swap(V[first], V[last]);
			last--;
		}
	}
	cout << "the vector V with even numbers first: ";
	for (auto i = V.begin(); i != V.end(); i++) {
		cout << *i << ", ";
	}
}
/*Write a program that takes an array A and an index i into A, and rearranges the elements such
that all elements less than A[i] (the “pivot”) appear first, followed by elements equal to the pivot,
followed by elements greater than the pivot.*/
void dutchFlagPartition() {
	vector<int> V = { 7, 13, 1, 9, 5, 3 };
	int pivot = 9;
	int smaller = 0;
	cout << "pivot: " << pivot;
	cout << endl << "Vector before dutch partition: ";
	for (auto i = V.begin(); i != V.end(); i++)
		cout << *i << ", ";
	//find all elements < pivot and swap with smaller index
	for (int i = 0; i < V.size(); i++) {
		if (V[i] < pivot) {
			swap(V[i], V[smaller]);
			smaller++;
		}
	}
	//alternative to below solution, find the pivot index(or keep track of it in above code) and
	//swap it with the element with smaller index. that way all elements > pivot fall on right hand side
	//auto it = find(V.begin(), V.end(), pivot);
	//if(it != V.end()) 
	//	swap(*it, V[smaller]);
	int larger = V.size() - 1;
	for (int i = V.size() - 1; i >= smaller; i--) { //smaller b/c all elements below smaller index are smaller than pivot
		if (V[i] > pivot) {
			swap(V[i], V[larger]);
			larger--;
		}
	}
	cout << endl << "Vector after dutch partition: ";
	for (auto i = V.begin(); i != V.end(); i++)
		cout << *i << ", ";
}
// largest - sum - contiguous - subarray---- kadane's algorithm
void maxSumSubArray(int a[], int n) {
	for (auto i = 0; i < n; i++)
		cout << a[i] << ", ";
	int max_sum = 0, max_tillnow = 0;
	for (int i = 0; i < n; i++) {
		max_tillnow = max_tillnow + a[i];
		if (max_tillnow < 0)
			max_tillnow = 0;
		if (max_sum < max_tillnow)
			max_sum = max_tillnow;
	}
	cout << "\nmax sum sub array = " << max_sum;
}
void twoPairSumToValue() {		//find the pair's whose sum is equal to 5
	vector<int> vec = { 2, 4, 1, 3, 6 };
	unordered_map<int, int> M;
	int sum = 5, s;
	for (int i = 0; i < vec.size(); i++)	//mark the entires as visited by assigning them value=1
		M[vec[i]] = 1;
	for (int i = 0; i < vec.size(); i++) {
		s = sum - vec[i];					//search for entry sum-vec[i], if it's 1..then sum=5
		if (M[s] == 1) {
			cout << vec[i] << " & " << s << endl;
			M[vec[i]] = 0;					//needed because we don't duplicate pairs like 1&4 and 4&1
		}
	}
}
