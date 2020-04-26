#ifndef CIRCULAR_H
#define CIRCULAR_H

#include <stdexcept>
#include "list.h"
#include "iterators/bidirectional_iterator.h"
using namespace std;
// TODO: Implement all methods
template <typename T>
class CircularLinkedList : public List<T> {
private:
    Node<T>* sentinel;
    public:
        CircularLinkedList() : List<T>() {
            this->head = this->tail = nullptr;
            this->sentinel = nullptr;
            this->nodes = 0;
        }

        T front(){
            if( this->head ) {
                return this->head->data;
            }
            else {
                throw out_of_range("Empty list!");
            }
        }

        T back(){
            if(this->tail) {
                return this->tail->data;
            }
            else {
                throw out_of_range("Empty list!");
            }
        }

        void push_front(T value){
            auto newNode = new Node<T>;
            newNode->data = value;

            if(!this->head) {
                auto sentinel = new Node<T>;
                this->sentinel = sentinel;

                this->head = this->tail = newNode;
                this->head->prev = this->tail->next = this->sentinel;
                this->sentinel->next = this->head;
                this->sentinel->prev = this->tail;
            }
            else {
                this->head->prev = newNode;
                newNode->next = this->head;
                this->head = newNode;
                this->head->prev = this->sentinel;
                this->sentinel->next = this->head;
            }
            this->nodes++;
        }

        void push_back(T value){
            auto newNode = new Node<T>;
            newNode->data = value;

            if(!this->head) {
                auto sentinel = new Node<T>;
                this->sentinel = sentinel;

                this->head = this->tail = newNode;
                this->head->prev = this->tail->next = this->sentinel;
                this->sentinel->next = this->head;
                this->sentinel->prev = this->tail;
            }
            else {
                this->tail->next = newNode;
                newNode->prev = this->tail;
                this->tail = newNode;
                this->tail->next = this->sentinel;
                this->sentinel->prev = this->tail;
            }
            this->nodes++;
        }

        void pop_front(){
            auto temp = this->head;
            this->head = this->head->next;
            this->sentinel->next = this->head;
            this->head->prev = this->sentinel;
            delete temp;
            this->nodes--;
        }

        void pop_back(){
            auto temp = this->tail;
            this->tail = this->tail->prev;
            this->tail->next = this->sentinel;
            this->sentinel->prev = this->tail;
            delete temp;
            this->nodes--;
        }

        T operator[](int index){
            auto it = begin();
            for(int i = 0 ; i < index ; ++i) {
                ++it;
            }
            return *it;
        }

        bool empty(){
            return (!this->head);
        }

        int size(){
                return this->nodes;
        }

        void clear(){
            if(!empty()) {
                delete this->sentinel;
                this->head->killSelf();
                this->nodes = 0;
            }
        }

        void sort(){}

        void reverse(){
            if(this->head) {
                T tempArray[this->nodes];
                int count = 0;
                auto itr = begin();

                for( ; itr != end() ; ++itr) {
                    tempArray[count] = *itr;
                    count++;
                }

                for(int i = this->nodes-1 ; i >= 0 ; i--) {
                    pop_front();
                    push_back(tempArray[i]);
                }
            }
            else {
                throw out_of_range("List is empty!");
            }
        }

        BidirectionalIterator<T> begin(){
            if(this->head) {
                auto it = BidirectionalIterator<T>(this->head);
                return it;
            }
            else {
                throw out_of_range("Empty list!");
            }
        }
	    BidirectionalIterator<T> end(){
            if(this->tail) {
                auto it = BidirectionalIterator<T>(this->tail->next);
                return it;
            }
            else {
                throw out_of_range("Empty list!");
            }
        }

        string name() {
            return "Circular Linked List";
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
        void merge(CircularLinkedList<T>&){}
};

#endif