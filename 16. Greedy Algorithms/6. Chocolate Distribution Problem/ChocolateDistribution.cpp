#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
public:
    /* Question: Given an array A[ ] of positive integers of size N, where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are M students, the task is to distribute chocolate packets among M students such that :
    1. Each student gets exactly one packet.
    2. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum. */

    // Time Complexity: O(n log(n))
    // Space Complexity: O(1)
    long long findMinDiff(vector<long long> arr, long long n, long long m)
    {
        sort(arr.begin(), arr.end());

        long long start = 0;
        long long end = m - 1;

        long long diff = INT_MAX;

        while (end < n)
        {
            diff = min(diff, arr[end++] - arr[start++]);
        }

        return diff;
    }
};

int main(void)
{
    vector<long long> arr{3, 4, 1, 9, 56, 7, 9, 12};
    long long n = arr.size();
    long long m = 5;

    // Solution.
    Solution S;
    cout << S.findMinDiff(arr, n, m);
    return 0;
}