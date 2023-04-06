/*
Question :-
You are given an array "arr" of size "n" and elements in the array are in the range of 1 to n-1. All elements in the array appear exactly once except for one element, your task is to return that element.

Example :
arr = {1,2,3, 4,4}; all elements appear exactly once, except for one element i.e, 4. So, our answer is 4.

*/

#include <bits/stdc++.h>
using namespace std;

/* ------------------------- Solution Class ------------------------------- */
class Solution
{
private:
public:
    /* Brute Force Approach 1 :- using nested loops. */
    // Time Complexity :- O(n^2)
    // Space Complexity :- O(1)
    int findDuplicate_Approach_1(vector<int> &arr)
    {

        // size of vector.
        int n = arr.size();

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] == arr[j])
                {
                    return arr[i];
                }
            }
        }

        return -1;
    }

    /* Brute Force Approach 2 :- using sorting. */
    // Time Complexity :- O(n log(n))
    // Space Complexity :- O(1)
    int findDuplicate_Approach_2(vector<int> &arr)
    {

        // size of vector.
        int n = arr.size();

        // sort the given vector.
        sort(arr.begin(), arr.end());

        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] == arr[i + 1])
            {
                return arr[i];
            }
        }

        return -1;
    }

    /* Approach 3 :- using unordered_map. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(n)
    int findDuplicate_Approach_3(vector<int> &arr)
    {

        // size of vector.
        int n = arr.size();

        // unodered_map
        unordered_map<int, int> frequency;

        // storing the frequency for each element.
        for (int i = 0; i < n; i++)
        {
            int element = arr[i];
            frequency[element]++;
        }

        // if any element having frequency > 1, that element is our answer.
        for (auto i : frequency)
        {
            if (i.second > 1)
            {
                return i.first;
            }
        }

        return -1;
    }

    /* Approach 4 :- using Bitwise Xor(^) operator.

    Algorithm :-
    step 1:- store the xor of all the elemnets of array in a variable.
    step 2:- take the xor of all element from 1 to n-1.
    step 3:- return answer.

    Dry Run :- arr = {1,2,3,4,4}


    // Step 1: xoring of all array elements.

    iterate 0 to n-1,
    xorr = 1^2^3^4^4; [4 ^ 4 = 0 and 1^2^3 = 0 and 0^0 = 0].
    xorr = 0;

    // Step 2: take the xor of all element from 1 to n-1.
    iterate 1 to n-1,
    xorr = 1^2^3^4; [1^2^3 = 0 and 0^4 = 0].
    xorr = 4;

    */

    // Time Complexity :- O(n)
    // Space Complexity :- O(1)
    int findDuplicate_Approach_4(vector<int> &arr)
    {

        // size of vector.
        int n = arr.size();

        int xorr = 0;

        for (int i = 0; i < n; i++)
        {
            xorr = xorr ^ arr[i];
        }

        for (int i = 1; i < n; i++)
        {
            xorr = xorr ^ i;
        }

        return xorr;
    }
};

int main()
{
    Solution S;

    vector<int> arr = {1, 2, 3, 4, 4};

    cout << S.findDuplicate_Approach_1(arr) << endl;
    cout << S.findDuplicate_Approach_2(arr) << endl;
    cout << S.findDuplicate_Approach_3(arr) << endl;
    cout << S.findDuplicate_Approach_4(arr) << endl;
}