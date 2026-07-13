#include <iostream>
#include  "Stack.h"

template <typename T>
Stack<T>::Stack() {
	top = -1;
	arr = new T[100];
}

template <typename T>
void Stack<T>::operator+(T x) {
	if (top == 99) {
		std::cout << "\nStack overflow!!";
		return;
	}
	arr[++top] = x;
}

template <typename T>
void Stack<T>::operator-() {
	if (top == -1) {
		std::cout << "\nStack underflow!!!";
		return;
	}
	top--;
}
template <typename T>
int Stack<T>::peek() {
	return arr[top];
}
template <typename T>
bool Stack<T>::isEmpty() {
	if (top == -1)
		return true;
	return false;
}
template <typename T>
void Stack<T>::display() {
	for (int i = 0;i <= top;i++)
		std::cout << "\t" <<arr[i];
}
template class Stack<int>;
