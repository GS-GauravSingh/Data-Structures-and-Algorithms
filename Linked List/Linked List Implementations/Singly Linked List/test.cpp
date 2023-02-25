#include <bits/stdc++.h>
#include "SinglyLinkedList.h"
using namespace std;

int main()
{
    SinglyLinkedList<string> sll;
    sll.push_back("Hello");
    sll.push_back("How");
    sll.push_back("are");
    sll.push_back("you");

    sll.printSinglyList();

    // sll.deleteAt(0);
    sll.deleteAt(3);

    sll.printSinglyList();
}