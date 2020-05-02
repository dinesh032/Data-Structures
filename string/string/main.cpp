#include<iostream>
#include<string>
#include"strProblems.h"
using namespace std;

int main() {
	findIO();
	string str = intToString(-143);
	cout << "string: " << str;
	//notpos();
	string s1 = "A man, a plan, a canal: Panama";
	bool flag = isPalindrome(s1);
	if (flag) {
		cout << "String \"" << s1 << "\" is a palindrome." << endl;
	}
	else {
		cout << "String \"" << s1 << "\" is NOT a palindrome." << endl;
	}
	//passByreference(s);
	//cout << "string after resize: " << s << endl;
	string str1 = "welcome to f5 networks";
	cout << str1 << endl;
	reverseString(str1);
	str1 = "geeks for geeks";
	cout << "string: " << str1 << endl;
	removeDups(str1);
	return 0;
}