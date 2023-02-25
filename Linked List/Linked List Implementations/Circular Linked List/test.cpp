#include<bits/stdc++.h>
#include "CircularSinglyLinkedList.h"
using namespace std;

int main()
{
    CircularSinglyLinkedList<int> cll;

    cll.push_back(1);
    cll.push_back(2);
    cll.push_back(3);
    cll.push_back(4);
    cll.printCircularSinglyList();

    cll.pop_front();
    cll.pop_front();
    cll.pop_front();
    cll.pop_front();
    cll.pop_front();



    cll.printCircularSinglyList();



    
}