/*
Question: There are given N ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their lengths. The task is to connect the ropes with minimum cost.

Example: arr[] = {4, 3, 2, 6};
Output: 29

Explanation: We can connect the ropes in following ways.
1) First connect ropes of lengths 2 and 3.
Which makes the array {4, 5, 6}. Cost of this operation 2+3 = 5.

2) Now connect ropes of lengths 4 and 5.
Which makes the array {9, 6}. Cost of this operation 4+5 = 9.

3) Finally connect the two ropes and all ropes have connected.
Cost of this operation 9+6 = 15

Total cost for connecting all ropes is 5 + 9 + 15 = 29.

------------------------------------- Approach ----------------------------------------------
We have 2 choices,
1. Everytime, take two ropes of minimum length, connect them and find the total cost.
2. Everytime, take two ropes of maximum length, connect them and find the total cost.

Lets dry run both the choices with one example.

Example: arr = {4,2,3,6};

Choice 1. Everytime, take two ropes of minimum length, connect them and find the total cost.

1) First connect ropes of lengths 2 and 3.
Which makes the array {4, 2+3, 6} => {4,5,6}.
Cost of this operation 2+3 = 5.

2) Now connect ropes of lengths 4 and 5.
Which makes the array {4+5, 6} => {9,6}. Cost of this operation 4+5 = 9.

3) Finally connect the two ropes and all ropes have connected.
Cost of this operation 9+6 = 15

Overall Cost using choice 1 is 5 + 9 + 15 =  29.


Choice 2. Everytime, take two ropes of maximum length, connect them and find the total cost.
1) First connect ropes of lengths 4 and 6.
Which makes the array {2, 3, 4+6} => {2,3,10}.
Cost of this operation 4+6 = 10.

2) Now connect ropes of lengths 3 and 10.
Which makes the array {2,3+10} => {2,13}. Cost of this operation 3+10 = 13.

3) Finally connect the two ropes and all ropes have connected.
Cost of this operation 2+13 = 15

Overall Cost using choice 2 is 10 + 13 + 15 = 38.

We can clearly see that, we can find the optimal answer using choice 1.

You can use Min Heap to Extract ropes of minimum length.
*/

#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
public:
    long long connectRopes(int *arr, int n)
    {
        // Min Heap.
        priority_queue<int, vector<int>, greater<int>> pq;

        // push all elements into min heap.
        for (int i = 0; i < n; i++)
        {
            pq.push(arr[i]);
        }

        // variable to store the minimum cost of connecting ropes.
        int cost = 0;

        // Traverse the Min Heap.
        while (pq.size() >= 2)
        {
            // take out 2 ropes of minimum length.

            // 1st rope.
            int rope1 = pq.top();
            pq.pop();

            // 2nd rope.
            int rope2 = pq.top();
            pq.pop();

            // Join both the ropes and push it into the min heap.
            int joinRopes = rope1 + rope2;
            pq.push(joinRopes);

            // Calculate the cost.
            cost += rope1 + rope2;
        }

        // return the minimum cost.
        return cost;
    }
};

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);

    // Solution.
    Solution S;
    cout << "Minimum Cost for connecting all ropes are " << S.connectRopes(arr, n) << ".\n";
}