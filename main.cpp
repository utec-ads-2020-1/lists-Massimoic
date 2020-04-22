#include <iostream>
//#include "test/tester.h"
#include "structures/queue.h"
#include "structures/stack.h"


using namespace std;

/*int main(int argc, char *argv[]) {
    cout << "===========================================================" << endl;
    cout << "\tLists Practice" << endl;
    cout << "===========================================================" << endl << endl;

    Tester::execute();
    return EXIT_SUCCESS;
}*/

int main() {
    cout << "Hello world!" << endl;
    //stack test:...
    /*stack<int>* test = new stack<int>(10);
    cout << test->peak() << endl;
    cout << test->empty() << endl;
    test->push(2);
    test->push(3);
    cout << test->peak() << endl;
    cout << test->size() << endl;
    test->push(10);
    test->push(11);
    test->push(12);
    cout << test->size() << endl;
    cout << test->empty() << "\n\n";
    cout << test->peak() << endl;
    test->pop();
    cout << test->peak() << endl;*/

    /*auto* sTest = new stack<int>(5);
    sTest->push(10);
    sTest->push(20);
    sTest->push(30);
    sTest->push(40);
    sTest->push(50);
    cout << sTest->peak() << endl;
    cout << sTest->size() << endl;
    sTest->push(60);
    cout << sTest->peak() << endl;
    cout << sTest->size() << endl;
    sTest->push(70);
    cout << sTest->peak() << endl;
    cout << sTest->size() << endl;
    sTest->push(80);
    cout << sTest->peak() << endl;
    cout << sTest->size() << endl;
    cout << sTest->getCapacity() << endl;*/

    // Queue test:...
    auto* qTest = new queue<int>(4);
    //cout << qTest->back() << endl;
    //cout << qTest->front() << endl;
    qTest->push(10);
    qTest->push(20);
    qTest->push(30);
    qTest->push(40);
    qTest->push(50);
    cout << "Front: " << qTest->front() << endl;
    cout << "Back: " << qTest->back() << endl;
    cout << "Size: " << qTest->size() << "\n";
    cout << "Capacity: " << qTest->getCapacity() << "\n\n";
    qTest->pop();
    cout << "Front: " << qTest->front() << endl;
    cout << "Back: " << qTest->back() << endl;
    cout << "Size: " << qTest->size() << endl;

    return 0;
}
