#ifndef BIDIRECTIONAL_ITERATOR_H
#define BIDIRECTIONAL_ITERATOR_H

#include "../node.h"

// TODO: Implement all methods
template <typename T> 
class BidirectionalIterator {
    private:
        Node<T> *current;

    public:
        BidirectionalIterator() = default;
        BidirectionalIterator(Node<T>* node){
            current = node;
        }

        BidirectionalIterator<T> operator=(BidirectionalIterator<T> it){
            current = it;
            return current;
        }

        bool operator!=(BidirectionalIterator<T> it){
            return (it.current != current);
        }

        BidirectionalIterator<T> operator++(){
            current = current->next;
            return current;
        }

        BidirectionalIterator<T> operator--(){
            current = current->prev;
            return current;
        }

        T operator*(){
            return current->data;
        }
};

#endif