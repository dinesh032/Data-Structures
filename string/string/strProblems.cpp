#include<iostream>
#include<string>
#include"strProblems.h"
using namespace std;
void findIO() {
	string str;	//string to find substr "IO" in below string
	string profileData = "RWI|IO|rogers-rwi|rogers-rwi|en-CA|en-CA|en-CA|COS_107_RWI_RSLE|false|false";
	int found = profileData.find_first_of("|");
	found++;
	while (profileData[found] != '|') {
		str = str + profileData[found++];
	} cout << str;
}
void printStr(string& str, int t, int l) {
	while (l <= t) {
		cout << str[l++];
	}
	cout << " ";
}
void reverseString(string& str) {	//reverse string word by word
	int len = str.size() - 1;
	int temp = len;
	while (len >= 0) {
		if (str[len] != ' ') {
			len--;
		}
		if (str[len] == ' ') {
			printStr(str, temp, len + 1);
			len--;
			temp = len;
		}
		if (len == 0) {
			printStr(str, temp, len);
			len--;
		}
	}
}
int isPalindrome(string A) {	//ignore uppercase, lowercase and special characters for comparsion
	int len = A.size() - 1;
	int i = 0;
	while (i <= len) {
		A[i] = tolower(A[i]);
		i++;
	}
	i = 0;
	while (i < len) {
		if (!isalpha(A[i]))		//isalnum and isdigit are other functions
			i++;
		else if (!isalpha(A[len]))
			len--;
		else if (A[i] == A[len]) {
			i++; len--;
			continue;
		}
		else {
			return 0;
		}
	}
}
//using hashmaps to remove duplicates
void removeDups(string& str) {
	int temp;
	int low_index = 0; int high_index = 0;
	bool a[256] = { 0 };
	while (str[high_index] != '\0') {
		temp = str[high_index];
		if (a[temp] == 0) {
			str[low_index++] = str[high_index];
			a[temp] = 1;
		}
		high_index++;
	}
	str.resize(low_index);
	cout << "\nstring without duplicates: " << str;
}
string intToString(int x) {
	string s;
	bool isNegative = false;
	if (x < 0)
		isNegative = true;
	while (x) {
		s += '0' + abs(x % 10);
		x = x / 10;
	}
	if (isNegative)
		s += '-';
	return { s.rbegin(), s.rend() };	//send reverse iterators, as the real string is filled in rev order
}
void passByreference(string& str) {		//passed by reference, no need of & and * like in C, resize here gets effected in str of main()
	str.resize(6);
}