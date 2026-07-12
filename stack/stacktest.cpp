#include "Stack.h"
#include <iostream>
using namespace std;

int main() {
    Stack s;
    cout << "Pushing elements:\n";
    s + 10;
    s + 20;
    s + 30;
    s.display();
    cout << "\nPopping element:\n";
    -s;
    s.display();
    cout << "\nPopping remaining elements:\n";
    -s;
    -s;
    s.display();
    cout << "\nTesting underflow:\n";
    -s;
    cout << "\nTesting overflow:\n";
    for (int i = 0; i < 101; i++) {
        s + i;
    }
    return 0;
}