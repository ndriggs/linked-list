#include "LinkedList.h"
#include <string>
#include <iostream>

using namespace std;

int main(){
    LinkedList<int> line;
    cout << "about to add 1" << endl;
    line.insertHead(1);
    cout << line.toString() << endl;
    cout << "just tostringed 1" << endl;
    cout << line.size() << endl;
    line.insertTail(2);
    cout << line.toString() << endl;
    cout << line.size() << endl;
    line.insertTail(4);
    cout << line.toString() << endl;
    cout << line.size() << endl;
    line.insertTail(5);
    cout << line.toString() << endl;
    cout << line.size() << endl;
    line.insertHead(0);
    cout << line.toString() << endl;
    cout << line.size() << endl;
    line.insertAfter(3, 2);
    cout << line.toString() << endl;
    cout << line.size() << endl;
    return 0;
} 