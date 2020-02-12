#include<iostream>
#include<string>
using namespace std;

void notpos() {
	string str;	//string to find substr "IO" in below string
	string profileData = "RWI|\"6\"|rogers-rwi|rogers-rwi|en-CA|en-CA|en-CA|COS_107_RWI_RSLE|false|false";
	
	cout << profileData << endl;
	if (profileData.find("\"6\"") == std::string::npos) {
		cout << "\"6\" not present" << endl;
	}
	else
		cout << "\"6\" present" << endl;
}
void findIO() {
	string str;	//string to find substr "IO" in below string
	string profileData = "RWI|IO|rogers-rwi|rogers-rwi|en-CA|en-CA|en-CA|COS_107_RWI_RSLE|false|false";
	int found = profileData.find_first_of("|");
	found++;
	while (profileData[found] != '|') {
		str = str + profileData[found++];
	}
	cout << profileData << endl;
	cout << endl << str << endl;
}

bool isPalindrome(const string& s) {
	int i = 0;
	int j = s.size() - 1;
	while (i < j) {
		if (s[i] != s[j]) {
			return false;
		}
		i++;
		j--;
	}
	return true;
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
int main() {

	//findIO();
	string s = "malayalam";
	//bool flag = isPalindrome(s);
	//if (flag)
	//	cout << s << " is a plaindrome" << ", flag = " << flag;
	//else
	//	cout << s << " is not a plaindrome" << ", flag = " << flag;
	//string str = intToString(-143);
	//cout << "string: " << str;
	//notpos();
	passByreference(s);
	cout << "string after resize: " << s << endl;
	return 0;
}