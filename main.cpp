#include <iostream>
#include "test/tester.h"
#include "structures/queue.h"
#include "structures/stack.h"
#include "structures/lists/forward.h"
#include "structures/lists/linked.h"
#include "structures/lists/circular.h"


using namespace std;

int main(int argc, char *argv[]) {
    cout << "===========================================================" << endl;
    cout << "\tLists Practice" << endl;
    cout << "===========================================================" << endl << endl;


    Tester::execute();

    return EXIT_SUCCESS;
}

/*

int main() {
    cout << " --------------------- " << endl << " -- Testing Linked List --" << "\n\n";
    LinkedList<int> linked;
    cout << "Is empty: " << linked.empty() << endl;
    cout << "Size: " << linked.size() << endl << endl;

    cout << "Pushing (front) 3 elements: 11,22,33" << endl;
    linked.push_front(11);
    linked.push_front(22);
    linked.push_front(33);
    cout << linked.front() << " " << linked[1] << " " << linked.back() << endl;
    cout << "Size: " << linked.size() << endl;

    cout << endl << "Pushing (back) 3 elements: 44,55,66" << endl;
    linked.push_back(44);
    linked.push_back(55);
    linked.push_back(66);
    cout << linked[3] << " " << linked[4] << " " << linked[linked.size()-1] << endl;
    cout << "Size: " << linked.size() << endl;
    cout << "Is Empty: " << linked.empty() << endl << endl;

    cout << "Pop front ----" ;
    linked.pop_front();
    cout << "Front : " << linked.front() << endl;
    cout << "Pop back ----" ;
    linked.pop_back();
    cout << "Back : " << linked.back() << endl << endl;

    cout << " --- Current list ---" << endl;
    for(int i = 0 ; i < linked.size() ; i++) {
        cout << linked[i] << " ";
    }
    cout << "\n\n";
    cout << " --- Reversing ---" << endl;
    linked.reverse();
    for(int i = 0 ; i < linked.size() ; i++) {
        cout << linked[i] << " ";
    }
    linked.push_back(8);
    linked.push_back(9);
    linked.push_back(6);

    LinkedList<int> linked2;
    linked2.push_back(80);
    linked2.push_back(45);
    linked2.push_back(63);
    linked2.push_back(21);
    linked2.push_back(79);

    cout << endl << " --- Linked Sort test --- " <<  endl;
    for(int i = 0 ; i < linked.size() ; i++) {
        cout << linked[i] << " ";
    }
    linked.sort();
    cout << endl << " --- sorted --- " << endl;
    for(int i = 0 ; i < linked.size() ; i++) {
        cout << linked[i] << " ";
    }

    linked2.sort();
    cout << "\n\n --- Merge test ---" << endl;
    cout << "\n --- Lista 1 --- " << endl;
    for(int i = 0 ; i < linked.size() ; i++) {
        cout << linked[i] << " ";
    }
    cout << "\n --- Lista 2 ---" << endl;
    for(int i = 0 ; i < linked2.size() ; i++) {
        cout << linked2[i] << " ";
    }
    linked.merge(linked2);

    cout << "\n ---- Merged List ----" << endl;
    for(int i = 0 ; i < linked.size() ; i++) {
        cout << linked[i] << " ";
    }


    cout << "\n\n" << "---- Testing Circular ----" << "\n\n";
    CircularLinkedList<int> circular;
    cout << "Is empty: " << circular.empty() << endl;
    cout << "Size: " << circular.size() << endl << endl;

    cout << "Pushing (front) 3 elements: 11,22,33" << endl;
    circular.push_front(11);
    circular.push_front(22);
    circular.push_front(33);
    cout << circular.front() << " " << circular[1] << " " << circular.back() << endl;
    cout << "Size: " << circular.size() << endl;

    cout << endl << "Pushing (back) 3 elements: 44,55,66" << endl;
    circular.push_back(44);
    circular.push_back(55);
    circular.push_back(66);
    cout << circular[3] << " " << circular[4] << " " << circular[circular.size()-1] << endl;
    cout << "Size: " << circular.size() << endl;
    cout << "Is Empty: " << circular.empty() << endl << endl;

    cout << "Pop front ----" ;
    circular.pop_front();
    cout << "Front : " << circular.front() << endl;
    cout << "Pop back ----" ;
    circular.pop_back();
    cout << "Back : " << circular.back() << endl << endl;

    cout << " --- Current list ---" << endl;
    for(int i = 0 ; i < circular.size() ; i++) {
        cout << circular[i] << " ";
    }
    cout << endl << "Size: " << circular.size() << endl;
    cout << "\n\n";
    cout << " --- Reversing ---" << endl;
    circular.reverse();
    for(int i = 0 ; i < circular.size() ; i++) {
        cout << circular[i] << " ";
    }

    cout << "\n\n ------= Sort test =------ \n";
    circular.push_back(71);
    circular.push_back(3);
    circular.push_back(156);
    circular.push_back(99);
    cout << " --- Unsorted list --- \n";
    for(int i = 0 ; i < circular.size() ; i++) {
        cout << circular[i] << " ";
    }
    circular.sort();
    cout << "\n --- Sorted list --- \n";
    for(int i = 0 ; i < circular.size() ; i++) {
        cout << circular[i] << " ";
    }
    cout << "\n\n ==== Merge Test ==== \n";
    CircularLinkedList<int> circular2;
    circular2.push_front(10);
    circular2.push_front(15);
    circular2.push_front(88);
    circular2.push_front(69);
    circular2.push_front(420);

    cout << " --- List 1 --- \n";
    for(int i = 0 ; i < circular.size() ; i++) {
        cout << circular[i] << " ";
    }

    cout << "\n --- List 2 --- \n";
    for(int i = 0 ; i < circular2.size() ; i++) {
        cout << circular2[i] << " ";
    }

    cout << "\n ----- Merged list ----- \n";
    circular.merge(circular2);
    for(int i = 0 ; i < circular.size() ; i++) {
        cout << circular[i] << " ";
    }
    cout <<"\n List 2 size: " << circular2.size() << endl;

    cout << "\n\n --- clear test ---\n";
    circular2.push_front(1);
    circular2.push_front(2);
    circular2.push_front(3);
    circular2.push_front(4);

    return 0;

}

*/
