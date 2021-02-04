#ifndef __MYPOINTQUEUE_H__
#define __MYPOINTQUEUE_H__

#include "Point.h"

class MyPointQueue
{

private:
    Point *data;
    int size;
    void resize(int newSize);

public:
    MyPointQueue();
    MyPointQueue(const Point arr[], const int size);
    MyPointQueue(const MyPointQueue &o);
    ~MyPointQueue();

    void push(const Point &p);

    void pop();

    int getSize() const;

    void print() const;
};

#endif