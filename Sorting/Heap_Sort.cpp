#include <iostream>
#include <vector>
using namespace std;
void swap(vector<int>& arr, int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
void heapify(vector<int>& arr, int i,int max) {
	int left = i * 2 + 1;
	int right = i * 2 + 2;
	int largest = i;
	if (left<max && arr[left]>arr[largest]) 
		largest = left;
	if (right<max && arr[right]>arr[largest])
		largest = right;
	if (largest != i) {
		swap(arr, i, largest);
		heapify(arr, largest,max);
	}
}
void buildheap(vector<int>& arr) 
{
	for (int i = (arr.size() / 2) - 1;i >= 0;i--) {
		heapify(arr, i,arr.size());
	}
}
void sort(vector<int>& arr) {
	buildheap(arr);
	for (int i = arr.size() - 1;i > 0;i--) {
		swap(arr, i, 0);
		heapify(arr, 0,i);	
	}
}
int main() {
	int n;
	cout << "\nEnter size: ";
	cin >> n;
	vector<int> arr(n);
	cout << "\nEnter elements: ";
	for (int i=0;i<arr.size();i++)
		cin >> arr[i];
	sort(arr);
	cout << "\nAfter sorting: ";
	for (int i=0;i<arr.size();i++)
		cout <<"\t"<< arr[i];
}