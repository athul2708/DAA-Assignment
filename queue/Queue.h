#pragma once

class Queue {
private:
    int arr[100];
    int front;
    int rear;

public:
    Queue();

    void operator+(int x);  // enqueue
    void operator-();       // dequeue
    void display();
};