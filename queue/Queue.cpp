#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue() {
    front = 0;
    rear = -1;
}

void Queue::operator+(int x) {
    if (rear == 99) {
        cout << "Queue Overflow\n";
        return;
    }

    arr[++rear] = x;
}

void Queue::operator-() {
    if (front > rear) {
        cout << "Queue Underflow\n";
        return;
    }

    front++;
}

void Queue::display() {
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