#include<iostream>
#include<vector>
#include<algorithm>
#include<forward_list>
#include<list>
#include<set>
#include<map>
#include<queue>
#include<stack>
using namespace std;

void stlVectors() {
	cout << "VECTORS" << endl;
	vector<int> A = { 1,2,3,4,5 };

	//cout << A[0] << endl;
	sort(A.begin(), A.end()); //1,2,3,4,5

	A.push_back(8);	//1,2,3,4,5,8
	A.push_back(8);
	A.push_back(8);
	A.push_back(8);
	A.push_back(8);
	A.push_back(12);
	A.push_back(13);
	A.push_back(15);
	A.pop_back();	//delete the last element
	cout << "vector A in reverse: ";
	for (auto i = A.rbegin(); i != A.rend(); i++)	//reverse iterators
		cout << *i << " ";
	cout << endl;
	cout << "vector A: ";	//print vector A
	for (auto i = A.begin(); i != A.end(); i++)
		cout << *i << " ";
	cout << endl;
	vector<int>::iterator it = lower_bound(A.begin(), A.end(), 8); // >= returns 8
	auto it1 = upper_bound(A.begin(), A.end(), 8); //  > returns 11

	cout << "lower bound of vector A: "<<*it << " & upper bound of vector A: " << *it1 << endl;
	cout << "No. of "<<*it<<" in vector A = "<<it1 - it << endl; //no. of 8's in vector A, sub of address pointers

	bool flag = A.empty();	//empty vector check function
	if (flag)
		cout << "vector is empty" << endl;
	else
		cout << "vector is not empty" << endl;

	cout << "Capacity of A: " << A.capacity() << ", Size of A: " << A.size() << endl; //always capacity > size, as vectors are dynamic arrays
	A.shrink_to_fit();	//reduces the capacity of vector to its size, now capacity = size
}
void stlSets() {
	cout << endl << "SETS" << endl;
	set<int> S;
	S.insert(3);
	S.insert(1);
	S.insert(9);
	S.insert(5);	//1,3,5,9..sets sort the entries as it's implemneted as BST
	S.erase(5);
	S.insert(6);
	S.insert(4);	//1,3,4,6,9
	for (auto i : S) {
		cout << i << " ";
	}
	auto it = S.find(3);	//
	if (it != S.end()) {
		cout << endl << "element " << *it << " found"<< endl;
	}
	else {
		cout << "element NOT found" << endl;
	}
	auto itr = S.equal_range(4);	//combo of lower_bound and upper_bound functions
	cout << "Lower bound of 4: " << *itr.first << ", Upper bound of 4: " << *itr.second << endl;
}
void stlLists() {
	cout << endl << "LISTS" << endl;
	forward_list<int> list;
	forward_list<int> splice_list = {45,2};
	list.push_front(1);	//push at front
	list.push_front(5);
	list.push_front(9);
	list.push_front(15);
	list.push_front(22);	//22, 15, 9, 5, 1
	list.pop_front();		//pop at front, now list is 15, 9, 5, 1
	cout << "printing the list: ";
	for (auto& x : list) {
		cout << x << " ";
	}
	auto it = list.begin();
	list.insert_after(it, 1, 14);	//insert 14 after it element, i.e 15, 14, 9, 5, 1
	list.insert_after(it, { 12,11,10 });	//insert 12,11,10 after it i.e 15,12,11,10,14,9,5,1
	list.erase_after(it);		//deletes 12 as it is now pointing to 15 i.e 15,11,10,14,9,5,1
	cout << endl<< "list: ";
	for (auto& x : list) {
		cout << x << " ";
	}
	cout << endl << "splice_after list: ";
	for (auto& x : splice_list) {
		cout << x << " ";
	}
	list.splice_after(it, splice_list); //transfer splice_list contents to list after it, 15,45,2,11,10....
	cout << endl << "list after splice_after: ";
	for (auto& x : list) {
		cout << x << " ";
	}
	list.sort();
	cout << endl<< "the sorted list: ";
	for (auto& x : list) {
		cout << x << " ";
	}
	list.reverse();
	cout << endl<< "reversed list: ";
	for (auto& x : list) {
		cout << x << " ";
	}
	cout << endl;
}
void stlMaps() {
	cout << endl << "MAPS" << endl;
	map<char, int> M;
	string s = "dinesh kumar bangla";
	for (auto i : s)
		M[i]++;
	cout << "String is: " << s << endl;
	cout << "no. of a's = " << M['a'] << " & no of n's = " << M['n'] << endl << endl;

	//find and delete a value
	auto it1 = M.find('h');
	if (it1 != M.end())
		M.erase(it1);
	cout << "M map after a delete: " << endl;
	for (auto i = M.begin(); i != M.end(); ++i) {
		cout << i->first << "=>" << i->second << "\n";
	}cout << endl;

	map<int, int> M1;
	M1.insert(pair<int, int>(1, 10));
	M1.insert(pair<int, int>(34, 20));
	M1.insert(pair<int, int>(3, 30));
	M1.insert(pair<int, int>(4, 40));
	M1.insert(make_pair(5, 50));	//another way to insert
	M1[6] = 60;						//another way to insert
	
	cout << "M1 map: " << endl;
	for (auto i = M1.begin(); i != M1.end(); ++i) {
		cout << i->first << "=>" << i->second<<"\n";
	}
	auto it = M1.insert(make_pair(3, 43));	//false insert as key 3 already exists
	if (it.second == false)					//second will return false
		cout << endl<< "Element key 3 already exists." << endl;
	M1.erase(34);	//delete with key value

}
void stlOthers() {
	queue<int> Q;
	Q.push(4);
	Q.push(7);
	Q.push(2);
	Q.push(9);
	Q.push(1);	//1,9,2,7,4
	cout << endl << "Queue is: ";
	while (!Q.empty()) {
		cout << Q.front() << ", ";
		Q.pop();
	}cout << endl;

	stack<int> S;
	S.push(7);
	S.push(6);
	S.push(5);
	S.push(3);
	S.push(1);
	cout << "Stack elements: ";
	while (!S.empty()) {
		cout << S.top() << ", ";
		S.pop();
	}
}
int main() {
	//stlVectors();
	//stlLists();
	//stlSets();
	//stlMaps();
	//stlOthers();

	//vector of pairs, similar to maps. Used when required the indexed access
	vector< pair<string, int> > V;
	V.push_back(make_pair("dinesh", 20));
	cout << "size of vector: " << V[0].first<<", "<<V[0].second << endl;
	return 0;
}