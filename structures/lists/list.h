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

        void mergeSort(T arr[],int l, int r) {
            if(l < r) {
                int m = (l+r)/2;
                mergeSort(arr,l,m);
                mergeSort(arr,m+1, r);
                mergeArr(arr, l, m, r);
            }
        }

        void mergeArr(T arr[], int l, int m, int r) {
            int size1 = m - l + 1;
            int size2 = r - m;

            T left[size1], right[size2];

            for (int i = 0 ; i < size1 ; i++) {
                left[i] = arr[l + i];
            }
            for(int j = 0 ; j < size2 ; j++) {
                right[j] = arr[m + j + 1];
            }

            int i = 0, j = 0;
            int merged;
            for(merged = l ; merged <= r && i < size1 && j < size2; merged++) {
                if(left[i] <= right[j]) {
                    arr[merged] = left[i];
                    i++;
                }
                else {
                    arr[merged] = right[j];
                    j++;
                }
            }
            for(; i < size1 ; i++) {
                arr[merged] = left[i];
                merged++;
            }

            for(; j < size2 ; j++) {
                arr[merged] = right[j];
                merged++;
            }

        }

    public:
        List() : head(nullptr), tail(nullptr), nodes(0) {};
        ~List(){
            delete head;
            delete tail;
        }

    void test(){}
        virtual T front() = 0;
        virtual T back() = 0;
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