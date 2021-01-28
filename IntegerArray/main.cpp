#include <iostream>
#include "IntegerArray.h"
#include "IntegerArray.cpp"

using namespace std;

int main()
{

    IntegerArray a(3);

    a.print();

    a.fill(1);
    a.fill(2);
    a.fill(3);

    a.print();

    a.modify_value();

    a.print();

    a.push_back(3);

    a.print();

    a.remove();

    a.print();

    a.push_back(7);

    a.print();

    a.push_back(8);

    a.print();

    a.modify_value();

    a.print();

    return 0;
}
