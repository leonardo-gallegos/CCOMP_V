#include <iostream>
#include "PointArray.h"
#include "PointArray.cpp"
#include "Polygon.h"
#include "Polygon.cpp"
#include "Rectangle.h"
#include "Rectangle.cpp"
#include "Triangle.h"
#include "Triangle.cpp"

using namespace std;

int main() {

    // PROBANDO EL CONSTRUCTOR POR DEFECTO.
    PointArray pa;

    // PROBANDO EL CONSTRUCTOR CON ARGUMENTOS.
    Point a;
    Point b(4, 5);
    Point c(10, 0);
    Point arr[] = {a, b, c}; // arreglo de Points estático.
    int tam = sizeof(arr) / sizeof(arr[0]);


    PointArray pa2(arr, tam);

    //**************************************/

    Rectangle rec(a, b);

    Triangle tri(a, b, c);

    cout << rec.area() << endl;

    cout << tri.area() << endl;

    return 0;

}
