/*

Question:- Given an array of both positive and negative integers, the task is to compute sum of minimum and maximum elements of all sub-array of size k.

Examples:

Input : arr[] = {2, 5, -1, 7, -3, -1, -2},   K = 4
Output : 18

Explanation : Subarrays of size 4 are :
    {2, 5, -1, 7},   min + max = -1 + 7 = 6
    {5, -1, 7, -3},  min + max = -3 + 7 = 4
    {-1, 7, -3, -1}, min + max = -3 + 7 = 4
    {7, -3, -1, -2}, min + max = -3 + 7 = 4

    Missing sub arrays -

    {2, -1, 7, -3}
    {2, 7, -3, -1}
    {2, -3, -1, -2}
    {5, 7, -3, -1}
    {5, -3, -1, -2}
    and few more -- why these were not considered??
    Considering missing arrays result coming as 27

    Sum of all min & max = 6 + 4 + 4 + 4  = 18

Approach 1 (Brute Force):- Run two loops to generate all subarrays of size k and find maximum and minimum values. Finally, return sum of all maximum and minimum elements.
Time taken by this solution is O(n*k).
.
*/

#include <bits/stdc++.h>
using namespace std;

//--------------- Brute Force Code ----------------------
// Time Complexity:- O(n*k)
// Space Complexity:- O(1)

int sumOfMinMax(vector<int> arr, int k)
{
    int sum = 0;
    for (int i = 0; i <= arr.size() - k; i++)
    {
        int minn = INT_MAX;
        int maxx = INT_MIN;
        for (int j = i; j < k + i; j++)
        {
            minn = min(arr[j], minn);
            maxx = max(arr[j], maxx);
        }
        cout << endl;

        sum += minn + maxx;
    }

    return sum;
}

//--------------- Optimized Code using deque ----------------------
// Time Complexity:- O(n)
// Space Complexity:- O(k)

int sumOfMinMax_Optimized(vector<int> arr, int k)
{
    // maxi, mini is used to track minimum and maximum element in windows of size k.
    deque<int> maxi(k);
    // in maxi, values are in decreasing order.
    deque<int> mini(k);
    // in mini, values are in increasing order.

    //  addition of first k size window.
    for (int i = 0; i < k; i++)
    {
        // in 2 loops se ye hoga ki aapke current k size ke window me jo max or min element hoga vo maxi, or mini ke front pe present hoga.
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
        {
            maxi.pop_back();
        }

        while (!mini.empty() && arr[mini.back()] >= arr[i])
        {
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
    }

    int sum = 0;
    // calculating sum for first window of size k.
    sum += arr[maxi.front()] + arr[mini.front()];

    // remaining windows
    for (int i = k; i < arr.size(); i++)
    {

        // removal
        while (!maxi.empty() && 1 - maxi.front() >= k)
        {
            maxi.pop_back();
        }
        while (!mini.empty() && 1 - mini.front() >= k)
        {
            mini.pop_back();
        }

        // addition.
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
        {
            maxi.pop_back();
        }

        while (!mini.empty() && arr[mini.back()] >= arr[i])
        {
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);

        sum += arr[maxi.front()] + arr[mini.front()];
    }

    return sum;
}

int main()
{
    vector<int> arr = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;

    cout << "Sum = " << sumOfMinMax_Optimized(arr, k) << endl;
}