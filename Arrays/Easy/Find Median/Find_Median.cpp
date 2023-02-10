/*
Question :-
An unsorted array of size n is given. write a program to find the median of an array. The median of array is the middle element of a sorted array in case of odd number of elements in an array and average of middle two elements when the number of elements in an array is even.
*/

#include <bits/stdc++.h>
using namespace std;

/* -------------------------- Solution Class --------------------------------- */
class Solution
{
private:
public:

    // Time complexity :- O(n log(n))
    // Space complexity :- O(1)
    int findMedian(vector<int> &arr)
    {
        // size of vector.
        int n = arr.size();

        // sort the given vector.
        sort(arr.begin(), arr.end());

        // odd number of elements.
        int median;
        if (n & 1 == 1)
        {
            // median = (arr[n/2] + arr[n/2+1])/2;
            median = (arr[n / 2] + arr[n / 2 + 1]) / 2;
        }
        else
        {
            // even number of elements.
            // median = arr[n/2];
            median = arr[n / 2];
        }

        return median;
    }
};

int main()
{
    vector<int> arr = {1, 5, 2, 3, 9, 12, 6};

    Solution S;
    cout << "Median is : " << S.findMedian(arr);
}