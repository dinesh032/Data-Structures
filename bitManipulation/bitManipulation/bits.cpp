#include<iostream>
using namespace std;

void countSetBits() {
	int x = 8;
	short count = 0;
	cout << "no. of set bits in " << x << ": ";
	while (x) {
		count += x & 1;
		x >>= 1;
	}
	cout << count << endl;
}
int main() {
	countSetBits();
	return 0;
}
