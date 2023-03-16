/*
Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.

Example 1:
Input:- N = 5, A[] = {-8, 2, 3, -6, 10}, K = 2
Output:-  -8 0 -6 -6

Explanation :
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6

*/
#include <bits/stdc++.h>
using namespace std;

/* --------------------------- Solution Class ------------------------------- */
class Solution
{
private:
public:
    /* Approach : Using DE-Queue data structure. */
    // Time Complexity :- O(N), N is the size of the array.
    // Space Complexity :- O(K), O(K) because we use an additional data structure (DE-Queue) + O(N), O(N) is the space used by answer vector.
    vector<long long> printFirstNegativeInteger(long long int arr[], long long int N, long long int K)
    {
        // DE-Queue.
        deque<long long> dq;

        // Vector to store answer.
        vector<long long> ans;

        // Algorithm :-
        // Step 1 :- Insert 1st k elements into DE-Queue (AKA deque) and find the first -ve integer in this window (TIP : Insert only -ve elements into deque because we only care about -ve elements).

        // processing 1st window of size k.
        for (int i = 0; i < K; i++)
        {
            // push the -ve elements and ignore +ve elements.
            if (arr[i] < 0)
            {
                dq.push_back(i); // pushing the index of -ve element.
            }
        }

        // storing the first -ve element of first window of size k.
        // Because we only push the -ve elements into the deque. That's why, dq.front() will have the first -ve element of first window of size k.

        // Corner case, if there is no -ve elements in first window of size k. In this case our deque is empty and our answer is 0.
        if (dq.size() > 0)
        {
            // if dq is not empty.
            // Then, dq.front() will have the first -ve element of first window of size k.
            ans.push_back(arr[dq.front()]); // arr[dq.front()], because we had stored the index of the -ve element in the deque.
        }
        else
        {
            // if dq is empty, it means there is no -ve elements in the first window of size k.
            // So, in this case our answer is 0.
            ans.push_back(0);
        }

        // Step 2 :- Process remoainin window from K to arr.size() - 1.
        // i = K, because we already processed the 1st window of size k.
        for (int i = K; i < N; i++)
        {
            // while going to the next window, we have to pop one element from front.
            // if that element is not coming under the window size i.e., k.
            if (!dq.empty() && i - dq.front() >= K)
            {
                dq.pop_front();
            }

            // Push element.
            if (arr[i] < 0)
            {
                dq.push_back(i);
            }

            // Store answer.
            // Corner case, if there is no -ve elements in window of size k. In this case our deque is empty and our answer is 0.
            if (dq.size() > 0)
            {
                // if dq is not empty.
                // Then, dq.front() will have the first -ve element of first window of size k.
                ans.push_back(arr[dq.front()]); // arr[dq.front()], because we had stored the index of the -ve element in the deque.
            }
            else
            {
                // if dq is empty, it means there is no -ve elements in the window of size k.
                // So, in this case our answer is 0.
                ans.push_back(0);
            }
        }

        // return answer.
        return ans;
    }

    /* Method to print the vector. */
    void printVec(vector<long long> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main(void)
{
    long long int arr[] = {-8, 2, 3, -6, 10};
    long long int K = 2;
    long long int N = sizeof(arr) / sizeof(arr[0]);

    // Solution.
    Solution S;
    vector<long long> ans = S.printFirstNegativeInteger(arr, N, K);
    S.printVec(ans);
}