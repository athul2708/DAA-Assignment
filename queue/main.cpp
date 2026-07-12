#include "Queue.h"

int main() {
    Queue q;
    q + 10;
    q + 20;
    q + 30;

    q.display();
    -q;

    q.display();
    -q;
    -q;

    q.display();
    -q;

    return 0;
}