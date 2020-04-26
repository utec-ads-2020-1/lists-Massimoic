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
                return this->head->data;
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

            if (!this->head) {
                this->head = newNode;
                this->tail = newNode;
            } else {
                this->head->prev = newNode;
                newNode->next = this->head;
                this->head = newNode;
            }
            this->nodes++;
        }

        void push_back(T value){
            auto newNode = new Node<T>;
            newNode->data = value;

            if(!this->head) {
                this->head = this->tail = newNode;
            }
            else {
                this->tail->next = newNode;
                newNode->prev = this->tail;
                this->tail = newNode;
                this->tail->next = nullptr;
            }
            this->nodes++;
        }

        void pop_front() {
            auto temp = this->head;
            this->head = this->head->next;
            this->head->prev = nullptr;
            delete temp;
            this->nodes--;
        }

        void pop_back() {
            auto temp = this->tail;
            this->tail = this->tail->prev;
            delete temp;
            this->nodes--;
        }

        T operator[](int index) {
            auto it = begin();
            for(int i = 0 ; i < index ; ++i) {
                ++it;
            }
            return *it;
        }

        bool empty() {
            return !this->head;
        }

        int size() {
            return this->nodes;
        }

        void clear() {
            if(!empty()) {
                this->head->killSelf();
                this->nodes = 0;
            }
        }

        void sort(){
            T tempArray[this->nodes];
            int count = 0;
            auto itr = begin();

            for(; itr != end() ; ++itr) {
                tempArray[count] = *itr;
                count++;
            }
            this->mergeSort(tempArray, 0 ,this->nodes-1);

            for(int i = 0 ; i < this->nodes ; i++) {
                pop_front();
                push_back(tempArray[i]);
            }
        }

        void reverse(){
            if(this->head) {
                T tempArray[this->nodes];
                int count = 0;
                auto itr = begin();

                for (; itr != end(); ++itr) {
                    tempArray[count] = *itr;
                    count++;
                }

                for (int i = this->nodes - 1; i >= 0; i--) {
                    pop_front();
                    push_back(tempArray[i]);
                }
            }
            else {
                throw out_of_range("List is empty!");
            }
        }

        BidirectionalIterator<T> begin() {
            if(this->head) {
                auto it = BidirectionalIterator<T>(this->head);
                return it;
            }
            else{
                throw out_of_range("List empty");
            }
        }

	    BidirectionalIterator<T> end(){
            if(this->tail) {
                auto it = BidirectionalIterator<T>(this->tail->next);
                return it;
            }
            else {
                throw out_of_range("List empty");
            }
        }

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
        void merge(LinkedList<T>& list2){
            T tempArray[this->nodes + list2.size()];
            auto itr1 = begin();
            auto itr2 = list2.begin();
            int size = this->nodes + list2.size();
            int tempSize = this->nodes;
            int count = 0;

            for(; itr1 !=end() ; ++itr1) {
                tempArray[count] = *itr1;
                count++;
            }
            for(; itr2 != list2.end() ; ++itr2) {
                tempArray[count] = *itr2;
                count++;
            }

            cout << endl;
            for(int i =0 ; i <size ; i++) {
                cout << tempArray[i] << " ";
            }
            this->mergeSort(tempArray, 0, size - 1);
            cout << endl;
            for(int i =0 ; i <size ; i++) {
                cout << tempArray[i] << " ";
            }
            cout << endl;

            for(int i = 0 ; i < tempSize ; i++) {
                pop_front();
            }
            for(int i = 0 ; i < size ; i++) {
                push_back(tempArray[i]);
            }
        }
};

#endif