#include <iostream>
#include "MyQueue.h"

using namespace std;

int main() {

    MyQueue<int> s;
    MyQueue<int> r;
    
    for (int i{1}; i <= 5; i++) 
        s.push(i);
    
    for (int i{6}; i <= 10; i++) 
        r.push(i);

    cout << s.empty() << endl;
    
    cout << "Using push()" << endl;
    cout << "My queue s: ";
    s.print();
    cout << "My queue r: ";
    r.print();

    MyQueue<int> t = s + r;
    cout << "My queue t: ";
    cout << t;

    t.pop();
    cout << "Using pop()" << endl;
    cout << "My queue t: ";
    cout << t;
    t.pop();
    cout << "My queue t: ";
    cout << t;
    t.pop();
    cout << "My queue t: ";
    cout << t;
    t.pop();
    cout << "My queue t: ";
    cout << t;
    t.pop();
    cout << "My queue t: ";
    cout << t;
    
    return 0;
}
