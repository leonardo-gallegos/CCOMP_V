// Renzo Leonardo Gallegos Vilca

// Exercise 6.42

#include <iostream>
#include <cmath>

using namespace std;

class Point
{
private:
    double x, y;

public:
    Point() : x(0), y(0) {}
    Point(double x, double y) : x(x), y(y) {}

    double distance(Point p2)
    {
        Point p1;
        p1.x = x;
        p1.y = y;
        double dist = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
        return dist;
    }
};

int main()
{
    Point p1(1, 3);
    Point p2(7, 7);

    cout << "Distance between p1 and p2: " << p1.distance(p2);
}

// Exercise 6.49

#include <iostream>

using namespace std;

void tripleByValue(int count)
{
    count *= 3;
    cout << "Pass by value: " << count << endl;
};

void tripleByReference(int &count)
{
    count *= 3;
    cout << "\nPass by reference: " << count << endl;
};

int main()
{
    int count = 11;

    tripleByValue(count);
    cout << "After pass by value: " << count;

    tripleByReference(count);
    cout << "After pass by reference: " << count;
}

// Exercise 7.13

#include <iostream>
#include <array>
#include <iomanip>

using namespace std;

int main()
{
    array<int, 20> n{};
    int num = 0;
    cout << "Enter an integer between 10 and 100" << endl;
    for (size_t i{0}; i < n.size(); ++i)
    {
        num = 0;
        while (num < 10 || num > 100)
        {

            cout << "Enter number " << i + 1 << ": ";
            cin >> num;
        }
        if (num >= 10 && num <= 100)
        {
            for (size_t g{0}; g <= i; ++g)
            {
                if (g == i)
                {
                    n[i] = num;
                }
                else if (n[g] == num)
                {
                    cout << "Duplicate number!!!" << endl;
                    cout << "Enter number " << i + 1 << " again: ";
                    cin >> num;
                    --g;
                }
                else if (num < 10 || num > 100)
                {
                    cout << "Number must be between 10 and 100!!!" << endl;
                    cout << "Enter number " << i + 1 << " again: ";
                    cin >> num;
                    --g;
                }
            }
        }
    }
    cout << "Element" << setw(10) << "Value" << endl;
    for (size_t j{0}; j < n.size(); ++j)
    {
        cout << setw(7) << j << setw(10) << n[j] << endl;
    }
}

// Exercise 7.14

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    vector<int> n;
    int num = 0;
    cout << "Enter an integer between 10 and 100" << endl;
    for (int i{0}; i < 20; ++i)
    {
        num = 0;
        while (num < 10 || num > 100)
        {
            cout << "Enter number " << i + 1 << ": ";
            cin >> num;
        }
        if (num >= 10 && num <= 100)
        {
            for (int g{0}; g <= i; ++g)
            {
                if (g == i || i == 0)
                {
                    n.push_back(num);
                }
                else if (num == n[g])
                {
                    cout << "Duplicate number!!!" << endl;
                    cout << "Enter number " << i + 1 << " again: ";
                    cin >> num;
                    --g;
                }
                else if (num < 10 || num > 100)
                {
                    cout << "Number must be between 10 and 100!!!" << endl;
                    cout << "Enter number " << i + 1 << " again: ";
                    cin >> num;
                    --g;
                }
            }
        }
    }
    cout << "Element" << setw(10) << "Value" << endl;
    for (int j{0}; j < 20; ++j)
    {
        cout << setw(7) << j << setw(10) << n[j] << endl;
    }
}

// Exercise 7.30

#include <iostream>
#include <array>

using namespace std;

void printArray(array<int, 7> array, int start, int end)
{
    if (start < end)
    {
        cout << array[start] << " ";
        printArray(array, start + 1, end);
    }
};

int main()
{
    array<int, 7> n = {1, 2, 3, 4, 5, 6, 7};
    int start = 0;
    int end = n.size();

    printArray(n, start, end);
}

// Insertion Sort

#include <iostream>
#include <array>

using namespace std;

void insertionSort(array<int, 5> array, int n)
{
    int i;
    int j;
    int key;
    for (i = 1; i < n; i++)
    {
        key = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

void printArray(array<int, 5> array, int start, int end)
{
    if (start < end)
    {
        cout << array[start] << " ";
        printArray(array, start + 1, end);
    }
};

int main()
{
    array<int, 5> array = {5, 4, 3, 2, 1};
    int n = array.size() / sizeof(array[0]);
    int start = 0;
    int end = array.size();

    insertionSort(array, n);
    cout << "Insertion sort array: \n";
    printArray(array, start, end);

    return 0;
}

// Quick Sort

#include <iostream>
#include <array>

using namespace std;

void quickSort(array<int, 5> array, int low, int high)
{
    int i = low;
    int j = high;
    int pivot = array[(i + j) / 2];
    int temp;

    while (i <= j)
    {
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i <= j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (j > low)
        quickSort(array, low, j);
    if (i < high)
        quickSort(array, i, high);
}

void printArray(array<int, 5> array, int start, int end)
{
    if (start < end)
    {
        cout << array[start] << " ";
        printArray(array, start + 1, end);
    }
};

int main()
{
    array<int, 5> array = {5, 4, 3, 2, 1};
    int n = array.size() / sizeof(array[0]);
    int start = 0;
    int end = array.size();

    quickSort(array, 0, n);
    cout << "Quick sort array: \n";
    printArray(array, start, end);

    return 0;
}
