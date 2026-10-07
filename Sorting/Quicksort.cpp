#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>&, int, int);
void quicksort(vector<int>&, int, int);

int main() {
	cout << "\nEnter array size: ";
	int n;
	cin >> n;
	vector<int> arr(n);
	cout << "\nEnter arrray to sort: ";
	for (int i = 0;i < n;i++)
		cin >> arr[i];
	cout << "\nArray after sort: ";
	quicksort(arr, 0, n - 1);
	for (int i : arr)
		cout << "\t" << i;
	return 0;
}

int partition(vector<int>& arr, int begin, int end) {
	int p = arr[end];
	int i = begin - 1;
	for (int j = begin;j < end;j++) {
		if (arr[j] < p) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[end], arr[i + 1]);
	return i + 1;
}

void quicksort(vector<int>& arr, int begin, int end) {
	if (begin < end) {
		int p = partition(arr, begin, end);
		quicksort(arr, begin, p - 1);
		quicksort(arr, p + 1, end);
	}
}