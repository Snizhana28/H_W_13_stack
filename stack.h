#include <algorithm>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

template <typename T> class stack {
private:
    T* conatiner;
    int top_elem;
    int size;
    void extend_memmory(int step_extend = 10) {
        size += step_extend;
        T* temp = new T[size];
        for (int i = 0; i < top_elem; i++) {
            temp[i] = conatiner[i];
        }
        delete[] conatiner;
        conatiner = temp;
    }

public:
    stack() {
        top_elem = -1;
        size = 10;
        this->conatiner = new T[size];
    }
    stack(int size) : conatiner() {
        this->size = size;
        this->conatiner = new T[size];
    }
    ~stack() { delete[] conatiner; }
    void push(T elem) {
        if (isFull()) {
            extend_memmory();
        }
        top_elem++;
        conatiner[top_elem] = elem;
    }
    T pop() {
        if (isEmpty()) {
            return 0;
        }
        else {
            top_elem--;
            T* temp = new T[size];
            for (size_t i = 0; i <= top_elem; i++) {
                temp[i] = conatiner[i];
            }
            delete[] conatiner;
            conatiner = temp;
        }
    }
    T top() { return conatiner[top_elem]; }
    void output() {
        for (size_t i = 0; i <= top_elem; i++) {
            if (conatiner[i] == conatiner[top_elem]) {
                cout << "item[" << i << "] = " << conatiner[i] << " <-[top]" << endl;
            }
            else {
                cout << "item[" << i << "] = " << conatiner[i] << endl;
            }
        }
    }
    int get_full_size() { return size; }
    bool isEmpty() { return (top_elem <= 0) ? true : false; }

    bool isFull() { return (top_elem == size) ? true : false; }
};