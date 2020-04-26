#ifndef LIST_H
#define LIST_H

#include "node.h"
#include <string>
using namespace std;

// TODO: Implement all methods
template <typename T>
class List {
    protected:
        Node<T>* head;
        Node<T>* tail;
        int nodes;

        void mergeSort(T arr[],T l, T r) {

        }

        void mergeArr(T arr[], T l, T m, T r) {
            T first, second, merged;
            T n1 = m - first + 1;
            T n2 = second - m;

            T left[n1], right[n2];
        }

    public:
        List() : head(nullptr), tail(nullptr), nodes(0) {};
        ~List(){
            delete head;
            delete tail;
        }

    void test(){}
        virtual T front() {
            if(head != nullptr) {
                return head->data;
            }
        }
        virtual T back() {
            if( tail != nullptr) {
                return tail->data;
            }
        }
        virtual void push_front(T) = 0;
        virtual void push_back(T) = 0;
        virtual void pop_front() = 0;
        virtual void pop_back() = 0;
        virtual T operator[](int) = 0;

        virtual bool empty() {
            return (head == nullptr && tail == nullptr && nodes == 0);
        }

        virtual int size() {
            return nodes;
        }

        virtual void clear() = 0;
        virtual void sort() = 0;
        virtual void reverse() = 0;
        virtual string name() = 0;
};

#endif