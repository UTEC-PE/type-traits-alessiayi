#include <iostream>

#include "slist.h"
#include "dlist.h"

using namespace std;

void testSimpleLinkedList();
void testDoubleLinkedList();

template <typename T>
struct Greater {
    bool operator()(T a, T b) {
        return a >= b; // What would happend without the =?
    }
};

template <typename T>
struct Less {
    bool operator()(T a, T b) {
        return a <= b; // What would happend without the =?
    }
};

struct Integer {
       typedef int T;
       typedef Less<T> Operation;
};

struct Float {
       typedef float T;
       typedef Greater<T> Operation;
};
/*
int main(int argc, char const *argv[]) {
    testSimpleLinkedList();
    testDoubleLinkedList();

    cin.get();
    return EXIT_SUCCESS;
}

void testSimpleLinkedList() {
    cout << "Simple Linked List" << endl;

    SList<Integer> integers;
    SList<Float> floats;

    SList<Integer>::iterator ite1;
    SList<Float>::iterator ite2;

    for (int i = 0; i < 5; i++) {
        integers.insert(2 * i + 1);
        floats.insert(20.f / (i + 1.f) + 2.f);
    }

    integers.remove(5);
    floats.remove(7);

    for (ite1 = integers.begin(); ite1 != integers.end(); ++ite1) {
        cout << *ite1 << " ";
    }
    cout << endl;

    for (ite2 = floats.begin(); ite2 != floats.end(); ++ite2) {
        cout << *ite2 << " ";
    }
    cout << endl << endl;
}

void testDoubleLinkedList() {
    cout << "Double Linked List" << endl;

    DList<Integer> integers;
    DList<Integer>::iterator ite;

    for (int i = 0; i < 5; i++) {
        integers.push_front(2 * i + 1);
    }

    ite = integers.begin();
    ++ite;
    cout << *ite << " ";
    ++ite;
    cout << *ite << " ";
    --ite;
    cout << *ite << " ";
    cout << endl << endl;
}*/
int main() {

  SList<Integer>* numbers=new SList<Integer>;

  numbers -> insert(5);
  numbers -> insert(2);
  numbers -> insert(6);
  numbers -> remove(2);

  cout << "Imprime normal: ";
  SListIterator<int> It=numbers -> begin();
  for (int i=0; i<3; i++){//print normal
    cout << *It << ",";
    ++It;
  }

  cout << endl;

  return 0;
}
