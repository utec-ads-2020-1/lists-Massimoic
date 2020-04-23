#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "iterators/forward_iterator.h"
using namespace std;

// TODO: Implement all methods
template <typename T>

class ForwardList : public List<T> {
public:
    ForwardList() : List<T>() {
        this->head = nullptr;
        this->nodes=0;
    }
        T front(){
        if(!empty()) {
            return this->head->data;
        } else {
            throw out_of_range("Empty list");
        }
    }
        T back(){}

        void push_front(T value){
        auto newNode = new Node<T>;
        newNode->data = value;

        if(!this->head) {
            this->head = newNode;
        }
        else {
            newNode->next = this->head;
            this->head = newNode;
        }
        this->nodes++;

    }

        void push_back(T){}

        void pop_front(){
        this->head = this->head->next;
        this->nodes--;
    }

        void pop_back(){}

        T operator[](int index){
        auto temp = new Node<T>;
        temp = this->head;
        for(int i = 0; i < index ; i++) {
            temp = temp->next;
        }
        return temp->data;
    }

        bool empty(){
            return (this->head  == 0 && this->nodes == 0);
        }

        int size(){
        return this->nodes;
    }
        void clear(){
        this->head->killSelf();
    }

        void sort(){}

        void reverse(){}

        ForwardIterator<T> begin(){}
	    ForwardIterator<T> end(){}

        string name() {
            return "Forward List";
        }

        /**
         * Merges x into the list by transferring all of its elements at their respective
         * ordered positions into the container (both containers shall already be ordered).
         *
         * This effectively removes all the elements in x (which becomes empty), and inserts
         * them into their ordered position within container (which expands in size by the number
         * of elements transferred). The operation is performed without constructing nor destroying
         * any element: they are transferred, no matter whether x is an lvalue or an rvalue,
         * or whether the value_type supports move-construction or not.
        */
        void merge(ForwardList<T>&);
};

#endif