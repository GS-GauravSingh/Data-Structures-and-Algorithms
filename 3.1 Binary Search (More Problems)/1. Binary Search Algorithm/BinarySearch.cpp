/*
About Binary Search :-

Binary Search is a searching algorithm used in a sorted arrayb y repeatedly dividing the search interval in half. The idea of binary search is to use the information that the array is sorted.

Time Complexity of Binary Search is O(log(n)).
Space Complexity of Binary Search is O(1).

Binary Search Algorithm :-
1. Initialize 2 pointer, low and high, low will be at 0 index and high at last index (n-1).
2. Run a loop till (low <= high).
3. Find the middle element.
4. Compare middle element with the given key,
5. If the key matches with the middle element, means key is found, return the index of the middle element.
6. If the middle element does not match the key, there can be 2 cases,
    1. middle element is greater than key,
        ==> If middle element is greater than key, then start searching for key on left half (mid - 1). Set high pointer to mid - 1.
        ==> Since the array is sorted in increasing order and if the middle element is greater than key, it means all the elements after mid are also greater than key. So, there is no point to search for key on right half. That's why we move to left half.

    2. middle element is less than key
        ==> If middle element is less than key, then start searching for key on right half (mid + 1). Set low pointer to mid + 1.
        ==> Since the array is sorted in increasing order and if the middle element is less than key, it means all the elements before mid are also lesser than key. So, there is no point to search for key on left half. That's why we move to right half.

7. return -1 if key not found.


** For calculation of Middle element you can below 2 methods, **

Method 1 :-  int mid = (low + high) / 2; // this will give integer overflow for larger size of array.

Method 2 :-  int mid = low + (high - low) / 2; // this will work perfectly for larger size of array.

*/

#include <bits/stdc++.h>
using namespace std;

/* Binary Search Algorithm.

Time Complexity: O(log(n)), where 'n' is the size of the nums vector.
Space Complexity: O(1).
*/
int binarySearch(vector<int> &nums, int target)
{
    // size of nums vector.
    int n = nums.size();

    // low and high Pointers.
    int low = 0;
    int high = n - 1;

    // Traverse the array and find the the index of target in nums vector.
    while (low <= high)
    {
        // Index of middle element.
        int mid = low + (high - low) / 2;

        // If nums[mid] == target, it means target found, so return the index of traget.
        if (nums[mid] == target)
        {
            return mid;
        }

        // Now, if nums[mid] < target, it means all the element before mid are also smaller than target (because input array is sorted).
        // So, set low = mid + 1.
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }

        // Now, if nums[mid] > target, it means all the element after mid are also greater than target (because input array is sorted).
        // So, set high = mid - 1.
        else
        {
            high = mid - 1;
        }
    }

    // return -1 in case of target does not present in the nums vector.
    return -1;
}

int main()
{

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 5;

    int idx = binarySearch(nums, target);

    if (idx != -1)
    {
        cout << "Key Found at Index " << idx << "." << endl;
    }
    else
    {
        // key not found.
        cout << "Key not Found." << endl;
    }
}