#ifndef QUEUE_H
#define QUEUE_H

using namespace std;

#define MAX 1000 

// TODO: Implement all methods
template <typename T>
class queue {
	T* data;
	int top;
	int capacity;
	int rear;
	int currentSize;

public:
	queue(int size = MAX) {
	    data = new T[size];
	    top = 0;
	    capacity = size;
	    rear = -1;
	    currentSize = 0;

	}
	~queue() {
	    delete[] data;
	}

	void push(T element) {
	    if ( capacity - currentSize == 0 ) {
	        capacity *= 2;
	        T* temp = new T[capacity];
	        int tempRear = -1;
	        for( int i = 0 ; i < currentSize ; i++) {
	            temp[++tempRear] = data[i];
	        }
	        delete data;
	        data = new T[capacity];
	        data = temp;
	        data[++rear] = element;
	        delete[] temp;
	    }
	    else {
	        data[++rear] = element;
	        currentSize++;
	    }
	}

	void pop() {
	    if (empty()) {
	        throw "Queue is Empty!";
	    }
	    else {
	        top = (top+1) % capacity;
	        currentSize--;
	    }
	}

	T front() {
	    if(empty()) {
	        throw "Queue is empty!";
	    }
	    else {
            return data[top];
        }
	}
    T back() {
	    if( empty() ) {
	        throw "Queue is empty!";
	    }
	    else {
            return data[rear];
        }
	}

	int size() {
	    return currentSize;
	}

	bool empty() {
	    return currentSize == 0;
	}

	int getCapacity() {
	    return capacity;
	}
};

#endif