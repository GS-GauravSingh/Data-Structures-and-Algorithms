#include <bits/stdc++.h>
#include "../1. Node for Singly Linked List/SinglyLinkedListNode.h"
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
public:
    /* Method that removes duplicates from Unsorted linked list. */
    // Approach 1 :- Using Nested loops.
    // Time Complexity :- O(n^2), n is the number of nodes in a linked list.
    // Space Complexity :- O(1)
    ListNode<int> *deleteDuplicates_Approach_1(ListNode<int> *head)
    {
        // Base Cases
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode<int> *i = head;
        while (i != NULL && i->next != NULL)
        {
            ListNode<int> *j = i->next;
            ListNode<int> *prev = i;

            while (j != NULL && j->next != NULL)
            {
                if (i->data != j->data)
                {
                    // unique element, move ahead.
                    prev = j;
                    j = j->next;
                }
                else
                {
                    // duplicate element.
                    ListNode<int> *nodeToDelete = j;

                    prev->next = j->next;
                    j = prev->next;

                    nodeToDelete->next = NULL;
                    delete nodeToDelete;
                }
            }

            i = i->next;
        }

        return head;
    }

    /* Method that removes duplicates from Unsorted linked list. */
    // Approach 2 :- Using Map.
    // Time Complexity :- O(n), n is the number of nodes in a linked list.
    // Space Complexity :- O(n)
    ListNode<int> *deleteDuplicates_Approach_2(ListNode<int> *head)
    {
        // Base Cases
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        // map to check if element is already apperar in the past or not.
        // if the element is already appear in the past, we simply delete that node otherwise we move ahead.
        unordered_map<int, bool> visited;

        // pointer to traverse linked list.
        ListNode<int> *currentNode = head;
        ListNode<int> *previousNode = NULL;

        while (currentNode != NULL && currentNode->next != NULL)
        {
            if (visited.find(currentNode->data) != visited.end())
            {
                // means, element already appear in the past.
                // In this case, simply delete this node.

                // node which we have to delete.
                ListNode<int> *nodeToDelete = currentNode;

                // connections.
                previousNode->next = currentNode->next;

                nodeToDelete->next = NULL;
                delete nodeToDelete;
            }
            else
            {
                // unique element.
                // insert element into map.
                visited[currentNode->data] = true;

                // and move ahead.
                // and don't forget to set the previous pointer.
                previousNode = currentNode;
            }

            // move pointer.
            currentNode = currentNode->next;
        }

        return head;
    }

    /* Method to Print Linked List. */
    void printList(ListNode<int> *&head)
    {
        ListNode<int> *ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->data << " -> ";
            ptr = ptr->next;
        }
        cout << "NULL\n";
    }
};

int main()
{
    // creating nodes of linked list.
    ListNode<int> *head;
    ListNode<int> *node2;
    ListNode<int> *node3;
    ListNode<int> *node4;
    ListNode<int> *node5;
    ListNode<int> *node6;

    // Initializing Nodes.
    node6 = new ListNode<int>(1);
    node5 = new ListNode<int>(2, node6);
    node4 = new ListNode<int>(2, node5);
    node3 = new ListNode<int>(2, node4);
    node2 = new ListNode<int>(2, node3);
    head = new ListNode<int>(4, node2);

    // Solution.
    Solution S;
    cout << "Before Removing Duplicates : ";
    S.printList(head);
    cout << "After Removing Duplicates : ";
    head = S.deleteDuplicates_Approach_2(head);
    S.printList(head);
}