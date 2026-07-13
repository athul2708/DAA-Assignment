#pragma once
template <typename T>
class Queue{
private:
    T arr[100];
    int front;
    int rear;

public:
    Queue();

    void operator+(T x); 
    void operator-();      
    void display();
};
