#include "LinkedList.h"
#include <string>
#include <iostream>

using namespace std;

int main(){
    LinkedList<string> line;
    line.insertHead("It's a beautiful day in the neighborhood");
    line.insertTail("a beautiful day in the neighborhood");
    line.insertTail("Oh won't you be mine");
    line.insertTail("Oh won't you be my neighbor!");
    line.insertHead("Lyrics to Mr. Rogers Neighborhood: ");
    line.insertAfter("Indeed it is Mr. Rogers", "It's a beautiful day in the neighborhood");
    cout << line.toString() << endl;
    return 0;
} 