#include <iostream>
//#include "test/tester.h"
#include "structures/queue.h"
#include "structures/stack.h"
#include "structures/lists/forward.h"


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
    cout << test->peak() << endl;*//*

    *//*auto* sTest = new stack<int>(5);
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
    cout << sTest->getCapacity() << endl;

    // Queue test:...
    *//*auto* qTest = new queue<int>(4);
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
    cout << "Size: " << qTest->size() << endl;*/

    ForwardList<int> lista;
    cout << "Pushing 10... " << endl;
    lista.push_front(10);
    cout << "front: " << lista.front() << endl;
    cout << "size: " << lista.size() << "\n\n";
    cout << "Pushing 20... " << endl;
    lista.push_front(20);
    cout << "front: " << lista.front() << endl;
    cout << "size: " << lista.size() << "\n\n";
    cout << "Popping front..." << endl;
    lista.pop_front();
    cout << "front: " << lista.front() << endl;
    cout << "size: " << lista.size() << endl;
    lista.push_front(33);
    lista.push_front(44);
    lista.push_front(55);
    lista.push_front(66);
    cout << "------ operator[] : "<< endl << endl;
    cout << lista[0] << " ";
    cout << lista[1] << " ";
    cout << lista[2] << " ";
    cout << lista[3] << endl << endl;

    cout << "Pushback..." << endl;
    lista.push_back(1);
    lista.push_back(2);
    lista.push_back(3);
    lista.push_back(4);
    cout << lista.back() << endl;
    cout << "Size: " << lista.size() << endl;
    cout << "Front : " << lista.front() << endl;
    for(int i = 0 ; i < lista.size()  ; i ++ ) {
        cout << lista[i] << " ";
    }
    cout << "\n\n";
    cout << "Testing pop_back..." << "\n\n";
    lista.pop_back();
    for(int i = 0 ; i < lista.size()  ; i ++ ) {
        cout << lista[i] << " ";
    }

    cout << "\n\n";
    cout << "Reverse/Clear/Iterator test..." << endl;
    lista.reverse();
    for(int i = 0 ;i < lista.size() ; i++) {
        cout <<lista[i] << " ";
    }
    cout << "\n\n" << "Merge test: " << endl;
    ForwardList<int> lista2;
    lista2.push_back(100);
    lista2.push_back(101);
    lista2.push_back(102);
    lista2.push_back(103);
    lista2.push_back(104);
    lista2.push_back(105);
    lista.merge(lista2);

    for(int i = 0 ; i < lista.size() ; i++) {
        cout << lista[i] << " ";
    }
    try {
        cout << endl << "front: " << lista2.front() << endl << "back: " << lista2.back() << endl;
    }
    catch (exception error) {
        cout << "--- " << error.what() << endl;
    }


    return 0;
}
