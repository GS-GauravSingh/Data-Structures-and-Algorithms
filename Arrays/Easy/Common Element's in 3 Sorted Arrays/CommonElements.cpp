/*
Question :-
Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
Note: can you take care of the duplicates without using any additional Data Structure?

Example 1:

Input:
n1 = 6; A = {1, 5, 10, 20, 40, 80}
n2 = 5; B = {6, 7, 20, 80, 100}
n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
Output: 20 80
Explanation: 20 and 80 are the only
common elements in A, B and C.


Expected Time Complexity: O(n1 + n2 + n3)
Expected Auxiliary Space: O(n1 + n2 + n3)
*/

#include <bits/stdc++.h>
using namespace std;

/* -------------- Solution Class ------------------------------- */

class Solution
{
public:
    /*
    Approach :-

    Step 1:- Find the intersection of array A and array B and store it in a seperate vector, let's called as temp.
    Step 2:- Now, Find the intersection of temp array and array C and store it in a seperate vector, let's called as ans.
    Step 3:- Return ans vector.

    Time Complexity :- O(n1 + n2 + n3)
    Space Complexity :- O(n1 + n2 + n3), in case of all common elements, then answer vector is of size n1+n2+n3.
    */
    vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
    {
        // vector to store intersection of array A and B.
        vector<int> intersection;

        // vector to store intersection of array intersection and C.
        vector<int> ans;

        // variables to traverse array A and B.
        int i = 0, j = 0;

        while (i < n1 && j < n2)
        {
            if (A[i] == B[j])
            {
                intersection.push_back(A[i]);

                // Skipping duplicates.
                while (i + 1 < n1 && A[i] == A[i + 1])
                {
                    i++;
                }
                while (j + 1 < n2 && B[j] == B[j + 1])
                {
                    j++;
                }

                i++;
                j++;
            }

            else if (A[i] < B[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }

        // variables to traverse array intersection and C.
        i = 0, j = 0;
        while (i < intersection.size() && j < n3)
        {
            if (intersection[i] == C[j])
            {
                ans.push_back(intersection[i]);

                // Skipping duplicates.
                while (i + 1 < n1 && intersection[i] == intersection[i + 1])
                {
                    i++;
                }
                while (j + 1 < n2 && C[j] == C[j + 1])
                {
                    j++;
                }

                i++;
                j++;
            }

            else if (intersection[i] < C[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }

        // return answer.
        return ans;
    }
};

int main()
{
    Solution S;

    int n1 = 6, A[] = {1, 5, 10, 20, 40, 80};
    int n2 = 5, B[] = {6, 7, 20, 80, 100};
    int n3 = 8, C[] = {3, 4, 15, 20, 30, 70, 80, 120};

    vector<int> ans = S.commonElements(A, B, C, n1, n2, n3);

    for (auto i : ans)
    {
        cout << i << " ";
    }
}