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
	stack(int size = MAX);
	~stack();   		

	void push(T) {
		if( capacity - top = 0) {
			capacity *= 2;
			T* temp = new T(capacity);
		}
	}
	void pop();
	T peak();

	int size();
	bool empty();
};

#endif