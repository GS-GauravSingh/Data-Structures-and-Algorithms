/*
Question:- Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

Ex:- arr  = {7,3,5,4,5,3,4}, n = 7

ans = 7.
*/

#include <bits/stdc++.h>
using namespace std;

/* Brute Force Approach :- Using Unordered_map. */
// Time Complexity:- O(n)
// Space Complexity:- O(n)
int singleNumber_BruteForce(vector<int> &a, int n)
{
    unordered_map<int, int> freq;
    for (int i = 0; i < a.size(); i++)
    {
        freq[a[i]]++;
    }

    for (auto i : freq)
    {
        if (i.second == 1)
        {
            return i.first;
        }
    }

    return -1;
}

/* Optimize Approach :- Using Xor(^) operator. */
// Time Complexity:- O(n)
// Space Complexity:- O(1)

/*
Xor (^) =
1 ^ 1 = 0
0 ^ 1 = 1
1 ^ 0 = 1
0 ^ 0 = 0
*/
int singleNumber(vector<int> &nums)
{
    int result = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        result = result ^ nums[i];
    }
    return result;
}

int main()
{
    vector<int> arr = {7, 3, 5, 4, 5, 3, 4};
    cout << singleNumber_BruteForce(arr, arr.size()) << endl;
    cout << singleNumber(arr) << endl;
}