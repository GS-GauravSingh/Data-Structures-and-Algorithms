#include <bits/stdc++.h>
using namespace std;

/* Function to find kth minimum Element of the Array. Tc:- O(n log(n)), SC:- O(1).  */
int findKthMinimum(vector<int> &arr, int k)
{
    sort(arr.begin(), arr.end());
    return arr[k - 1];
}

/* Function to find kth maximum Element of the Array. Tc:- O(n log(n)), SC:- O(1).  */
int findKthMaximum(vector<int> &arr, int k)
{
    sort(arr.begin(), arr.end());
    return arr[arr.size() - k];
}

int main()
{
    vector<int> arr = {10, 20, 3, 2, 6, 59, 87, 1};
    int k = 2;

    cout << "Kth Maximum Element:- " << findKthMaximum(arr, k) << endl;
    cout << "Kth Minimum Element:- " << findKthMinimum(arr, k) << endl;
}