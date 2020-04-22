#ifndef STACK_H
#define STACK_H
using namespace std;

#define MAX 1000

// TODO: Implement all methods
template <typename T>
class stack {
	T* data;
	int top;
	int capacity;

public:
	stack(int size = MAX) {
        data = new T[size];
        top = -1;
        capacity = size;
	}
	~stack() {
	    delete[] data;
	}

	void push(T element) {
	    if (capacity - top + 1 != 0) {
	        data[++top] = element;
	    }
	    else {
	        capacity *= 2;
	        T* temp = new T[capacity];
	        int tempTop = -1;
	        for( int i = 0 ; i < top+1 ; i++) {
	            temp[++tempTop] = data[i];
	        }
	        delete data;
	        data = new T[capacity];
	        data = temp;
	        data[++top] = element;
	        delete[] temp;
	    }
	}

	void pop() {
	    if (empty()) {
	        throw "stack is EMPTY";
	    }
	    top--;
	}

	T peak() {
	    return data[top];
	}

	int size() {
	    return top +1;
	}

	bool empty() {
	    return size() == 0;
	}

	int getCapacity() {
	    return capacity;
	}
};

#endif