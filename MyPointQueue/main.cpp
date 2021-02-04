#include <iostream>
#include "MyPointQueue.h"
#include "MyPointQueue.cpp"

using namespace std;

int main()
{

    Point a;
    Point b(1, 2);
    Point c(3, 4);
    Point d(5, 6);
    Point arr[] = {a, b, c};
    int tam = sizeof(arr) / sizeof(arr[0]);

    MyPointQueue s(arr, tam);

    cout << "My queue s: ";
    s.print();

    cout << "Using push()" << endl;
    cout << "My queue s: ";
    s.push(d);
    s.print();

    cout << "Using pop()" << endl;
    cout << "My queue s: ";
    s.pop();
    s.print();

    return 0;
}
