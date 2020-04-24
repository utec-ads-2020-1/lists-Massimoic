#ifndef FORWARD_ITERATOR_H
#define FORWARD_ITERATOR_H

#include "../node.h"

// TODO: Implement all methods
template <typename T> 
class ForwardIterator {
    private:
        Node<T> *current;

    public:
        ForwardIterator()= default;
        ForwardIterator(Node<T>* node){
            this->current = node;
        }

        ForwardIterator<T> operator=(ForwardIterator<T> it){

        }

        bool operator!=(ForwardIterator<T> it) {
            return (it.current != this->current);
        }

        ForwardIterator<T> operator++(){
            return this->current->next;
        }

        T operator*();
};

#endif