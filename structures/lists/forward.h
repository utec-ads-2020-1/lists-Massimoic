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
        this->tail = nullptr;
    }
        T front(){
        if(!empty()) {
            return this->head->data;
        } else {
            throw out_of_range("Empty list");
        }
    }
        T back() {
        if(!empty()) {
            return this->tail->data;
        }
        else {
            throw out_of_range("Empty list");
        }
    }

        void push_front(T value){
        auto newNode = new Node<T>;
        newNode->data = value;

        if(!this->head) {
            this->head = newNode;
            this->tail = newNode;
        }
        else {
            newNode->next = this->head;
            this->head = newNode;
        }
        this->nodes++;

    }

        void push_back(T value) {
        auto newNode = new Node<T>;

        if(!this->head) { //empty
            newNode->data = value;
            this->tail = newNode;
            this-> head = newNode;
        }
        else {
            this->tail->next = newNode;
            this->tail = newNode;
            this->tail->data = value;
        }
        this->nodes++;
    }

        void pop_front(){
        if(this->nodes == 1) {
            auto temp = this->head;
            this->head = this->tail = nullptr;
            delete temp;
            this->nodes = 0;
        }
        else {
            auto temp = this->head;
            this->head = this->head->next;
            delete temp;
            this->nodes--;
        }
    }

        void pop_back() {
        auto temp = this->head;
        for(int i = 0; i < this->nodes-2 ; i++) {
            temp = temp->next;
        }
        this->tail = temp;
        delete this->tail->next;
        this->nodes--;
    }

        T operator[](int index){
        auto temp = this->head;
        for(int i = 0; i < index ; i++) {
            temp = temp->next;
        }
        return temp->data;
    }


        bool empty(){
            return !this->head;
        }

        int size(){
        return this->nodes;
    }
        void clear(){
        if(!empty()) {
            this->head->killSelf();
            this->nodes =0;
        }
    }

        void sort() {
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

        void reverse() {
        if(this->head) {
            T tempArray[this->nodes];
            int count = 0;
            auto itr = begin();
            for(; itr != end();  ++itr ) {
                tempArray[count] = *itr;
                count++;
            }
            for(int i = this->nodes-1; i >= 0 ; i--) {
                pop_front();
                push_back(tempArray[i]);
            }
        }
        else {
            throw out_of_range("List is empty!");
        }
    }

        ForwardIterator<T> begin(){
        if(this->head) {
            auto it = ForwardIterator<T>(this->head);
            return it;
        }
    }
	    ForwardIterator<T> end() {
            if(this->tail) {
                auto it = ForwardIterator<T>(this->tail->next);
                return it;
            }
    }

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
        void merge(ForwardList<T>& list2) {
            /*auto itr2 = list2.begin();

            for(; itr2 != list2.end() ; ++itr2) {
                push_back(*itr2);
                list2.pop_front();
            }*/
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

            this->mergeSort(tempArray, 0, (this->nodes + list2.size()) - 1);

            for(int i = 0 ; i < tempSize ; i++) {
                pop_front();
            }
            for(int i = 0 ; i < size ; i++) {
                push_back(tempArray[i]);
            }
        }
};

#endif