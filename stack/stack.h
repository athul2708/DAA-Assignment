#pragma once

class Stack {
private:
    int top;
    int* arr;
public:
    Stack();

    void operator+(int x);    
    void operator-();   
    int peek();
    bool isEmpty();
    void display();
};