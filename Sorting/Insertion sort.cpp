#include <iostream>
using namespace std;
void insertion(int*, int);

int main() {
	cout << "\nEnter array size: ";
	int n;
	cin >> n;
	int* arr = new int[n];
	cout << "\nEnter array to sort: ";
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	cout << "\nArray after sort: ";
	insertion(arr, n);
	for (int i = 0;i < n;i++)
		cout << "\t" << arr[i];
	delete[] arr;
	return 0;
}

void insertion(int* arr, int n) {
	for (int i = 1;i < n;i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}
