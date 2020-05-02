#include<iostream>
#include<vector>
#include<algorithm>
#include"array.h"
using namespace std;

int main() {
	int a[] = { -2, -3, 6, -1, -2, 1, 5, -3 };
	int n = sizeof(a) / sizeof(a[0]);
	//maxSumSubArray(a, n);
	//evenNumbersFirst();
	//dutchFlagPartition();
	twoPairSumToValue();
	return 0;
}