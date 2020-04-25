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
            current = it;
            return current;
        }

        bool operator!=(ForwardIterator<T> it) {
            return (it.current != current);
        }

        ForwardIterator<T> operator++(){
            current = current->next;
            return current;
        }

        T operator*(){
            return current->data;
        }
};

#endif