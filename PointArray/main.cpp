#include <iostream>
#include "PointArray.h"
#include "PointArray.cpp"

using namespace std;

int main()
{

    // PROBANDO EL CONSTRUCTOR POR DEFECTO.
    PointArray pa;
    cout << pa.getSize() << endl;

    // PROBANDO EL CONSTRUCTOR CON ARGUMENTOS.
    Point a;
    Point b(1, 2);
    Point c(3, 4);
    Point arr[] = {a, b, c}; // arreglo de Points estático.
    int tam = sizeof(arr) / sizeof(arr[0]);

    PointArray pa2(arr, tam);
    cout << pa2.getSize() << endl;

    //**************************************/
    if (true)
    {
        // PROBANDO EL CONSTRUCTOR COPIA
        PointArray pa3 = pa2;
    }

    pa2.print();

    pa2.push_back(b);
    pa2.print();

    pa2.modify(0, b);
    pa2.print();

    pa2.modify(2, b);
    pa2.print();

    pa2.insert(3, c);
    pa2.print();

    pa2.insert(4, c);
    pa2.print();

    pa2.remove(0);
    pa2.print();

    return 0;
}
