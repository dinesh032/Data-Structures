#include<iostream>
#include<conio.h>

using namespace std;
// Explaination: http://www.geeksforgeeks.org/heap-sort/

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void heapify(int a[], int n, int i) {
	int largest = i;	
	int L = 2 * i + 1;	//Calculate left and right indices
	int R = 2 * i + 2;

	if (L < n && a[L] > a[largest])		//check if left node > root, if so assign index of left
		largest = L;
	if (R < n && a[R] > a[largest])		//same above operation for right
		largest = R;

	if (largest != i) {					//if one of above two operation passes, then swap &
		swap(a[largest], a[i]);			//heapify again on the remaining left or right subtree
		heapify(a, n, largest);		
	}
}

void heapSort(int a[], int n) {
	
	//build binary heap for n/2-1 non child nodes
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(a, n, i);	//here i is an index..we assume a[i] as the largest element for now..heapify 
							//function builds binary heap for this subtree
	for (int i = n - 1; i >= 0; i--)
	{
		swap(a[i], a[0]);	//swap last & first element. Now, last element is the maximum of array..
		heapify(a, i, 0);				//So now heapify only the remaining i elements now
	}
}
void kSmallestHeapify(int a[], int n, int k) {
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(a, n, i);
	for (int i = 0; i < k; i++) {
		cout << a[0] << ", ";
		swap(a[0], a[n - i - 1]);
		heapify(a, n-i-1, 0);
	}
	cout << endl;
}
int main() {
	
	int n, a[10];
	cout << "Enter the size of array: ";
	cin >> n;
	cout << "Enter elements of array: ";
	for (int i = 0; i < n; i++)
		cin >> a[i];

	cout << endl << "Unsorted array: ";
	for (int i = 0; i < n; i++)
		cout << a[i] << ", ";
	cout << endl;

	heapSort(a, n);

	cout << endl << "Sorted array using heap sort: ";
	for (int i = 0; i < n; i++)
		cout << a[i] << ", ";
	cout << endl;

	//k largest(or smallest) elements in an array using binary heap
	int k;
	cout << "Enter the k largest elements to be printed from array: ";
	cin >> k;
	kSmallestHeapify(a, n, k);

	_getch();
	return 0;
}