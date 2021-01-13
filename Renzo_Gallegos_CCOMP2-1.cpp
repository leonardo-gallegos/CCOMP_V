
#include <iostream>
#include <iomanip>

using namespace std;

// Exercise 2.16
int main()
{
    int a;
    int b;

    cout << "Enter first number: ";
    cin >> a;

    cout << "Enter second number: ";
    cin >> b;

    cout << "===================================" << endl;
    cout << left << setw(15) << "   Sum:"
         << a << "  +  " << b << "  = " << right << setw(4) << a + b << endl;
    cout << left << setw(15) << "   Product:"
         << a << "  x  " << b << "  = " << right << setw(4) << a * b << endl;
    cout << left << setw(15) << "   Difference:"
         << a << "  -  " << b << "  = " << right << setw(4) << a - b << endl;
    cout << left << setw(15) << "   Quotient:"
         << a << "  /  " << b << "  = " << right << setw(4) << a / b << endl;
    cout << "===================================" << endl;
}

// Exercise 2.18
int main()
{
    int a;
    int b;

    cout << "Enter first integer: ";
    cin >> a;

    cout << "Enter second integer: ";
    cin >> b;

    if (a > b)
    {
        cout << a << " is larger.";
    }
    else if (b > a)
    {
        cout << b << " is larger.";
    }
    else
    {
        cout << "These numbers are equal.";
    }
}

// Exercise 2.20
int main()
{
    int a;

    cout << "Enter circle's radius: ";
    cin >> a;

    cout << left << setw(15) << "Diameter:" << 2 * a << endl;
    cout << left << setw(15) << "Circumference:" << 2 * a * 3.14159 << endl;
    cout << left << setw(15) << "Area:" << 3.14159 * a * a << endl;
}

// Exercise 2.22
int main()
{
    cout << "*****\n****\n***\n**\n*\n " << endl;
}

// Exercise 2.24
int main()
{
    int a;
    int b;

    cout << "Enter first integer: ";
    cin >> a;

    cout << "Enter second integer: ";
    cin >> b;

    if (a % 2 == 1)
    {
        cout << a << " is an odd number." << endl;
    }
    else if (b % 2 == 1)
    {
        cout << b << " is an odd number" << endl;
    }
    else if ((a + b) % 2 == 1)
    {
        cout << a + b << " is an odd number" << endl;
    }
}

// Exercise 2.26
// Part 1
int main()
{
    cout << "* * * * * * * *" << endl;
    cout << " * * * * * * * *" << endl;
    cout << "* * * * * * * *" << endl;
    cout << " * * * * * * * *" << endl;
    cout << "* * * * * * * *" << endl;
    cout << " * * * * * * * *" << endl;
    cout << "* * * * * * * *" << endl;
    cout << " * * * * * * * *" << endl;
}
// Part 2
int main()
{
    string a;
    a = "* * * * * * * *\n * * * * * * * *";
    cout << a << endl
         << a << endl
         << a << endl
         << a;
}

// Exercise 2.28
int main()
{
    int a;

    cout << "Enter an integer: ";
    cin >> a;

    cout << a % (a / 10) << "  "
         << (a / 10) % (a / 100) << "  "
         << (a / 100) % (a / 1000) << "  "
         << (a / 1000);
}

// Exercise 2.30
int main()
{
    int height;
    int weight;

    // El problema quiere que usemos INT, es por eso
    // que usé centimetros ya que de esta forma puedo
    // usar un número entero como 185 cm y no 1.85 m
    cout << "Enter your height in centimeters: ";
    cin >> height;

    cout << "Enter your weight in kilograms: ";
    cin >> weight;

    int BMI = weight * 10000 / (height * height);

    cout << "Your BMI is: " << BMI << endl;
    cout << "=====================================" << endl;
    cout << "BMI VALUES" << endl;
    cout << "Underweight: \tless than 18.5" << endl;
    cout << "Normal: \tbetween 18.5 and 24.9" << endl;
    cout << "Overweight: \tbetween 25 and 29.9" << endl;
    cout << "Obeset: \t30 or greater" << endl;
    cout << "=====================================" << endl;
}

// Exercise 2.32
int main()
{
    int age;
    int stnd;
    int tnk;
    int glh;
    int nes;
    int max;
    int min;

    cout << "Enter your age: ";
    cin >> age;

    stnd = 220 - age;
    tnk = 208 - 0.7 * age;
    glh = 207 - 0.7 * age;
    nes = 211 - 0.64 * age;

    cout << "===================" << endl;
    cout << "MHR VALUES" << endl;
    cout << "Standard: "
         << "\t" << stnd << endl;
    cout << "Tanaka: "
         << "\t" << tnk << endl;
    cout << "Gellish: "
         << "\t" << glh << endl;
    cout << "Nes: "
         << "\t\t" << nes << endl;
    cout << "====================" << endl;

    if (stnd > tnk && stnd > glh && stnd > nes)
    {
        max = stnd;
    }
    else
    {
        if (tnk > stnd && tnk > glh && tnk > nes)
        {
            max = tnk;
        }
        else
        {
            if (glh > stnd && glh > tnk && glh > nes)
            {
                max = glh;
            }
            else
                max = nes;
        }
    }
    if (stnd < tnk && stnd < glh && stnd < nes)
    {
        min = stnd;
    }
    else
    {
        if (tnk < stnd && tnk < glh && tnk < nes)
        {
            min = tnk;
        }
        else
        {
            if (glh < stnd && glh < tnk && glh < nes)
            {
                min = glh;
            }
            else
                min = nes;
        }
    }
    cout << "Your MHR value must be between " << min << " and " << max;
}
