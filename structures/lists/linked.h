#ifndef LINKED_H
#define LINKED_H

#include <stdexcept>
#include "list.h"
#include "iterators/bidirectional_iterator.h"
using namespace std;
// TODO: Implement all methods
template <typename T>
class LinkedList : public List<T> {
    public:
        LinkedList() : List<T>() {
            this->head = this->tail = nullptr;
            this->nodes =0;
        }

        T front() {
            if(this->head) {
                return this->head.data;
            }
            else {
                throw out_of_range("Empty list");
            }
        }
        T back() {
            if(this->tail) {
                return this->tail->data;
            }
            else {
                throw out_of_range("Empty list");
            }
        }


        void push_front(T value) {
            auto newNode = new Node<T>;
            newNode->data = value;
            if(!this->head) {
                this->head = newNode;
                this->tail = newNode;
            }
            else {
                this->head->prev = newNode;
                newNode->next = this->head;
                this->head = newNode;
            }
            this->nodes++;
        }
        void push_back(T);
        void pop_front();
        void pop_back();
        T operator[](int);
        bool empty();
        int size();
        void clear();
        void sort();
        void reverse();

        BidirectionalIterator<T> begin();
	    BidirectionalIterator<T> end();

        string name() {
            return "Linked List";
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
        void merge(LinkedList<T>&);
};

#endif