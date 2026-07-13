#include "Queue.h"
#include <iostream>
using namespace std;

template <typename T>
Queue<T>::Queue() {
    front = 0;
    rear = -1;
}

template <typename T>
void Queue<T>::operator+(T x) {
    if (rear == 99) {
        cout << "Queue Overflow\n";
        return;
    }

    arr[++rear] = x;
}

template <typename T>
void Queue<T>::operator-() {
    if (front > rear) {
        cout << "Queue Underflow\n";
        return;
    }

    front++;
}

template <typename T>
void Queue<T>::display() {
    if (front > rear) {
        cout << "Queue is empty\n";
        return;
    }

    cout << "Queue: ";

    for (int i = front; i <= rear; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}
template class Queue<int>;
