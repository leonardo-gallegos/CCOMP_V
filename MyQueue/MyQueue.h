#ifndef __MYQUEUE_H__
#define __MYQUEUE_H__

#include <queue>

using namespace std;

template<typename T>
class MyQueue;

template<typename T>
MyQueue<T> operator + (const MyQueue<T> &s, const MyQueue<T> &r) {
    MyQueue<T> result = s;

    for(unsigned int i{0}; i < r.items.size(); i++)
    {
        result.items.push_back(r.items[i]);
    }
    return result;
}

template<typename T>
ostream& operator << (ostream &output, MyQueue<T> &s){

    for(unsigned int i = 0; i < s.items.size(); i++){
        if (i == 0){
            output << "[ " << s.items[i] << " ";
        }
        else if (i + 1 == s.items.size()){
            output << ", " << s.items[i] << " ]" << endl;
        }
        else{
            output << ", " << s.items[i] << " ";
        }
    }
    return output;
}

template <typename T>
class MyQueue {
        friend MyQueue<T> operator + <>(const MyQueue<T> &s, const MyQueue<T> &r);
        friend ostream& operator << <>(ostream &output, MyQueue<T> &s);
        deque <int> items;

    public:

        bool empty() const {
            return items.empty();
        }

        void push(const int &item) {
            items.push_back(item);
        }
       
        void pop() {
            items.pop_front();
        }

        void print(){
            for (int i{0}; i < items.size(); ++i){
                if (i == 0){
                    cout << "[ " << items[i] << " ";
                }
                else if (i + 1 == items.size()){
                    cout << ", " << items[i] << " ]";
                }
                else{
                    cout << ", " << items[i] << " ";
                }
            }
            cout << endl;
        }
};

#endif