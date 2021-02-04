#include <iostream>
#include "MyPointQueue.h"

MyPointQueue::MyPointQueue()
{
    size = 0;
    data = new Point[0];
}

MyPointQueue::MyPointQueue(const Point arr[], const int size)
{
    this->size = size;
    data = new Point[size];
    for (int i = 0; i < size; i++)
    {
        data[i] = arr[i];
    }
}

MyPointQueue::MyPointQueue(const MyPointQueue &o)
{
    this->size = o.size;
    data = new Point[o.size];
    for (int i = 0; i < size; i++)
    {
        data[i] = o.data[i];
    }
}

MyPointQueue::~MyPointQueue()
{
    delete[] data;
}

int MyPointQueue::getSize() const
{
    return size;
}

void MyPointQueue::print() const
{
    std::cout << "[ ";
    for (int i = 0; i < size; i++)
    {
        data[i].print();
        std::cout << " ";
    }
    std::cout << "]" << std::endl;
}

void MyPointQueue::resize(int newSize)
{
    Point *tmp = new Point[newSize];
    int minSize = (newSize > size) ? size : newSize;

    for (int i{0}; i < minSize; i++)
    {
        tmp[i] = data[i];
    }
    delete[] data;
    size = newSize;
    data = tmp;
}

void MyPointQueue::push(const Point &p)
{
    resize(size + 1);
    data[size - 1] = p;
}

void MyPointQueue::pop()
{
    for (int i = 0; i < size - 1; i++)
    {
        data[i] = data[i + 1];
    }
    resize(size - 1);
}
