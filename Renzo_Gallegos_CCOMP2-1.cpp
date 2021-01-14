#include <iostream>

using namespace std;

// Exercise 4.24
// Part 1
/*
int x = 5;
int y = 15; 
if ( y < 10 )
if ( x > 10 )
cout << "XxXxX" << endl;
else
cout << "YxYxY" << endl;
cout << "OoOoO" << endl;
*/
int main()
{
    int x = 5;
    int y = 15;
    // OoOoO
    int x = 5;
    int y = 15;
    // YxYxY
    // OoOoO

    if (y < 10)
        if (x > 10)
            cout << "XxXxX" << endl;
        else
            cout << "YxYxY" << endl;
    cout << "OoOoO" << endl;
}

// Exercise 4.24
// Part 2
/*
if ( y < 10 )
{
if ( x > 10 )
cout << "XxXxX" << endl;
}
else
{
cout << "YxYxY" << endl;
cout << "OoOoO" << endl;
}
*/
int main()
{
    int x = 5;
    int y = 15;
    //YxYxY
    //OoOoO
    int x = 15;
    int y = 5;
    //XxXxX

    if (y < 10)
    {
        if (x > 10)
            cout << "XxXxX" << endl;
    }
    else
    {
        cout << "YxYxY" << endl;
        cout << "OoOoO" << endl;
    }
}

// Exercise 4.26
int main()
{
    int size;

    cout << "Enter size of the side: ";
    cin >> size;

    if (size <= 20 && size >= 1)
    {
        for (int fil = 0; fil != size; fil++)
        {
            for (int col = 0; col != size; col++)
            {
                if (fil == 0 || fil == size - 1 || col == 0 || col == size - 1)
                    cout << "*";
                else
                    cout << " ";
            }
            cout << endl;
        }
    }
}

// Exercise 4.27
int main()
{
    int num;

    cout << "Enter an five-digit integer: ";
    cin >> num;
    
    int size = 0;
    int n = num;
    do
    {
        ++size;
        n /= 10;
    } while (n);
    if(size == 5)
    {
        int dig;
        int rev = 0;
        int x = num;

        do
        {
            dig = num % 10;
            rev = (rev * 10) + dig;
            num = num / 10;
        } while (num != 0);

        if (x == rev)
            cout << x <<" is a palindrome.";
        else
            cout << x << " is not a palindrome.";
    }
    else
    {
        cout << "The number must have five digits" << endl;
    }
}

// Exercise 4.28
int main()
{
    int bin;

    cout << "Enter a binary number: ";
    cin >> bin;

    int size = 0;
    int n = bin;
    do
    {
        ++size;
        n /= 10;
    } while (n);
    int dig;
    int res;
    int exp = 0;
    int ex = exp;
    int val;
    int result = 1;
    int sum = 0;

    do
    {
        dig = bin % 10;
        res = bin / 10;
        bin = res;
        result = 1;
        ex = exp;
        while (ex != 0)
        {
            result *= 2;
            --ex;
        }
        val = dig * result;
        sum = sum + val;
        exp++;
    } while (bin != 0);

    cout << "Decimal value: " << sum << endl;
}

// Exercise 4.30
int main()
{
    int x = 0, y = 1;
    while (true)
    {
        if (x == 0)
        {
            cout << x << endl;
            cout << y << endl;
        }

        x = x + y;
        cout << x << endl;

        y = x + y;
        cout << y << endl;
    }
}

// Exercise 4.32
int main()
{
    int x = 2, y = 3;
    cout << ++x + y;
}

// Exercise 4.33
int main()
{
    double a, b, c;
    cout << "Enter first side: ";
    cin >> a;
    cout << "Enter second side: ";
    cin >> b;
    cout << "Enter third side: ";
    cin >> c;
    if (a + b > c && a + c > b && b + c > a)
    {
        cout << a << ", " << b << " and " << c << " represent the sides of a triangle.";
    }
    else
    {
        cout << a << ", " << b << " and " << c << " don't represent the sides of a triangle.";
    }
}

// Exercise 4.35
// Part 1
int main()
{
    int x;
    int i = 1;
    int fact = 1;
    cout << "Enter a number: ";
    cin >> x;

    if (x != 0 && x != 1)
    {
        while (x >= i)
        {
            fact = fact * i;
            i = i + 1;
        }
        cout << x << "!"
             << " = "
             << fact;
    }
    else
    {
        cout << x << "!"
             << " = "
             << "1";
    }
}

// Exercise 4.35
// Part 2
int main()
{
    int x = 1;
    int i = 1;
    int n;
    double sum = 1;
    double fact = 1;
    cout << "Enter an accuracy for epsilon: ";
    cin >> n;

    for (int a = 1; a <= n; a++)
    {
        if (x != 0 && x != 1)
        {
            while (x >= i)
            {
                fact = fact * i;
                i = i + 1;
            }
        }
        sum = sum + 1 / fact;
        x = x + 1;
    }
    cout << sum;
}

// Exercise 4.35
// Part 3
int main()
{
    int x = 1;
    int i = 1;
    int n;
    int p;
    double result = 1;
    int exp = 1;
    int ex = exp;
    double sum = 1;
    double fact = 1;
    cout << "Enter an accuracy: ";
    cin >> n;

    cout << "Enter an exponent: ";
    cin >> p;

    for (int a = 1; a <= n; a++)
    {
        if (x != 0 && x != 1)
        {
            while (x >= i)
            {
                fact = fact * i;
                i = i + 1;
            }
        }
        result = 1;
        ex = exp;
        while (ex != 0)
        {
            result *= p;
            --ex;
        }
        sum = sum + result / fact;
        x = x + 1;
        exp++;
    }
    cout << sum;
}
