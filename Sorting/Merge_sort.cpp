#include <iostream>
using namespace std;
void mergesort(int*,int,int);
void merge(int*,int, int, int);
int main() {
	cout << "\nEnter array size: ";
	int n;
	cin >> n;
	int* arr = new int[n];
	cout << "\nEnter array to sort: ";
	for (int i=0;i<n;i++) {
		cin >> arr[i];
	}
	mergesort(arr, 0, n - 1);
	cout << "\nSorted array: ";
	for (int i = 0;i < n;i++)
		cout << "\t" << arr[i];
	delete[] arr;
	return 0;
}

void mergesort(int* arr, int start, int end) {
	int size = end - start + 1;
	int mid = (start + end) / 2;
	if (size > 1) {
		mergesort(arr, start, mid);
		mergesort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}

void merge(int* arr, int p, int m, int q) {
	int* temp = new int[q - p + 1];
	int k = 0;
	int i = p, j = m + 1;
	while (i <= m && j <= q) {
		if (arr[i] < arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	while (i <= m)
		temp[k++] = arr[i++];

	while (j <= q)
		temp[k++] = arr[j++];

	for (i = p, k = 0; i <= q; i++, k++)
		arr[i] = temp[k];

	delete[] temp;
}
