#include "IntegerArray.h"

#include <iostream>

using namespace std;

IntegerArray::IntegerArray(int size)
{
	this->data = new int[size]();
	this->size = size;
}

IntegerArray::IntegerArray(IntegerArray &o)
{
	this->data = new int[o.size];
	size = o.size;
	for (int i = 0; i < size; i++)
		data[i] = o.data[i];
}

IntegerArray::~IntegerArray()
{
	delete[] data;
}

void IntegerArray::print()
{
	for (int i{0}; i < size; i++)
	{
		if (i == 0)
		{
			cout << "{ " << data[i] << " , ";
		}
		else if (size == i + 1)
		{
			cout << data[i] << " }";
		}
		else
		{
			cout << data[i] << " , ";
		}
	}
	cout << endl;
}

void IntegerArray::modify_value()
{
	for (int i{0}; i < size; i++)
	{
		cout << "Enter an integer for index " << i << ": ";
		cin >> n;
		data[i] = n;
	}
}

//
void IntegerArray::fill(int num)
{
	if ((i_push < size) && (data[i_push] == 0))
	{
		data[i_push] = num;
		i_push++;
	}
	else if ((i_push == size) && (data[i_push] == 0))
	{
		cout << "All index values are filled" << endl;
	}
}

void IntegerArray::remove()
{
	if (size > 0)
	{
		size--;
	}
	i_push = size;
}

void IntegerArray::push_back(int num)
{
	if (i_push == size)
	{
		++size;
		data[i_push] = num;
	}
	i_push++;
}
