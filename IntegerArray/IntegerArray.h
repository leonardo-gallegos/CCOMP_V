#ifndef __INTEGER_ARRAY__
#define __INTEGER_ARRAY__

class IntegerArray
{

private:
    int *data;
    int size;
    int i_push;
    int n;

public:
    IntegerArray(int size);
    IntegerArray(IntegerArray &o);
    ~IntegerArray();
    void print();
    void modify_value();
    void push_back(int num);
    void remove();
    void fill(int num);
};

#endif
