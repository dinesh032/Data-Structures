#include<iostream>
#include<map>
#include<string>
#include<iterator>
using namespace std;

int main() {

	map<string, string> M;
	//M["$AMTEOn"] = "true";
	//M["$CreateOriginator"] = "IO";
	//M["$FaxAutoTransferOn"] = "true";
	M.insert(pair<string, string>("$AMTEOn", "true"));
	M.insert(pair<string, string>("$CreateOriginator","IO"));
	M.insert(pair<string, string>("$FaxAutoTransferOn","true"));

	auto itr = M.find(string("$CreateOriginator"));
	if (M.find(string("$CreateOriginator")) != M.end()) {
		string hostRef = M["$CreateOriginator"];
		cout << "hostRef: " << hostRef << endl;
		cout << "key value pair found: " << itr->first << "--->" << itr->second << endl << endl;
	}
	else {
		cout << "not found";
	}
	return 0;
}
