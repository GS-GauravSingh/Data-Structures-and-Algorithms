#include <bits/stdc++.h>
using namespace std;

class Solution
{

    // Time Complexity: O(n) + O(k), where 'n' is the size of the array.
    // Space Complexity: O(n).
    int findKthPositive_BruteForce(vector<int> &arr, int k)
    {

        // Initialize an unordered_set to store the elements of the input array 'arr'.
        unordered_set<int> set;

        // Iterate through each element in the input array 'arr' and insert it into the set.
        for (int i : arr)
        {
            set.insert(i);
        }

        // Initialize an integer j to 1. This variable will be used to track the current positive integer being checked.
        int j = 1;

        // Run a loop while k != 0.
        while (k != 0)
        {
            // if 'j' is not present in the array, it means 'j' is a missing numbers.
            if (set.find(j) == set.end())
            {
                // decrement k.
                k--;

                // And k == 0, it means this 'j' is the kth missing number.
                if (k == 0)
                    return j;
            }

            // Increment the value of 'j' to move to the next positive integer.
            // because we are checking value from 1 until we found the kth missing number.
            j++;
        }

        return -1;
    }

    // Time Complexity: O(n), where 'n' is the size of the array.
    // Space Complexity: O(1).
    int findKthPositive_Better(vector<int> &arr, int k)
    {

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] <= k)
            {
                k++;
            }
            else
            {
                break;
            }
        }

        return k;
    }

    // Time Complexity: O(log(n)), where 'n' is the size of the array.
    // Space Complexity: O(1).
    int findKthPositive_Optimized(vector<int> &arr, int k)
    {

        int low = 0;
        int high = arr.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            int missingElements = arr[mid] - (mid + 1); // Finding the missing elements till this index.

            if (missingElements < k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return k + high + 1;
    }

public:
    int findKthPositive(vector<int> &arr, int k)
    {

        // // Brute Force Solution.
        // return findKthPositive_BruteForce(arr, k);

        // // Better Approach.
        // return findKthPositive_Better(arr, k);

        // Optimized Approach.
        return findKthPositive_Optimized(arr, k);
    }
};

int main(void)
{
    vector<int> arr{2, 3, 4, 7, 11};
    int k = 5;

    // Solution.
    Solution obj;
    cout << k << "th missing element is: " << obj.findKthPositive(arr, k) << ".";
    return 0;
}