#pragma once
template<typename T>
class Stack {
private:
    int top;
    T* arr;
public:
    Stack();

    void operator+(T x);    
    void operator-();   
    int peek();
    bool isEmpty();
    void display();
};
