#include <iostream>
#include  "Stack.h"

Stack::Stack() {
	top = -1;
	arr = new int[100];
}

void Stack::operator+(int x) {
	if (top == 99) {
		std::cout << "\nStack overflow!!";
		return;
	}
	arr[++top] = x;
}
void Stack::operator-() {
	if (top == -1) {
		std::cout << "\nStack underflow!!!";
		return;
	}
	top--;
}
int Stack::peek() {
	return arr[top];
}
bool Stack::isEmpty() {
	if (top == -1)
		return true;
	return false;
}
void Stack::display() {
	for (int i = 0;i <= top;i++)
		std::cout << "\t" <<arr[i];
}