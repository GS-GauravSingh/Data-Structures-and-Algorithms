#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /* Optimal Approach: Using two-pointer. Let's dry run this approach.

    Let's say: nums = [1, 1, 2, 2, 3, 4, 5, 5].

    Initialize the pointer i to 0 i.e., i = 0.

    Now, Start iterating through the array with j starting from 1:

    >> At j = 1 and i = 0,
    nums =    [1, 1, 2, 2, 3, 4, 5, 5]
    pointers:  i  j

    nums[j] is equal to nums[i] (both are 1). So, we continue without making any changes.

    >> At j = 2 and i = 0,
    nums =    [1, 1, 2, 2, 3, 4, 5, 5]
    pointers:  i     j
    nums[j] is not equal to nums[i]. This means we have found a unique element.
    Now, Increment i by 1 (Now, i = 1) and then Swap nums[i] and nums[j]:

    After the above operations, The array becomes [1, 2, 1, 2, 3, 4, 5, 5].

    >> At j = 3 and i = 1,
    nums =     [1, 2, 1, 2, 3, 4, 5, 5].
    pointers:      i     j
    nums[j] is equal to nums[i] (both are 2). So, we continue without making any changes.

    >> At j = 4 and i = 1,
    nums =     [1, 2, 1, 2, 3, 4, 5, 5].
    pointers:      i        j
    nums[j] is not equal to nums[i].
    Now, Increment i by 1 (Now, i = 2) and then Swap nums[i] and nums[j]:

    After the above operations, The array becomes [1, 2, 3, 2, 1, 4, 5, 5].

    >> At j = 5 and i = 2,
    nums =      [1, 2, 3, 2, 1, 4, 5, 5].
    pointers:          i        j
    nums[j] is not equal to nums[i].
    Now, Increment i by 1 (Now, i = 3) and then Swap nums[i] and nums[j]:

    After the above operations, The array becomes [1, 2, 3, 4, 1, 2, 5, 5].


    >> At j = 6 and i = 3,
    nums =      [1, 2, 3, 4, 1, 2, 5, 5].
    pointers:             i        j

    nums[j] is not equal to nums[i].
    Now, Increment i by 1 (Now, i = 4) and then Swap nums[i] and nums[j]:

    After the above operations, The array becomes [1, 2, 3, 4, 5, 2, 1, 5].

    >> At j = 7 and i = 4,
    nums =     [1, 2, 3, 4, 5, 2, 1, 5]
    pointers:               i        j
    nums[j] is equal to nums[i] (both are 5). So, we continue without making any changes.

    At this point our 'j' pointer reaches to end of the array. The iteration ends, and 'i' now represents the index of the last unique element.

    Return i + 1, which is 5. The resulting array without duplicates is [1, 2, 3, 4, 5].


    Time Complexity: O(n), where 'n' is the size of the vector.
    Space Complexity: O(1).
    */
    int removeDuplicates(vector<int> &nums)
    {
        // Size of nums vector.
        int n = nums.size();

        // Initialize a pointer 'i' to track the previous element.
        // Initialiaze 'i' with 0. Initially 'i' is pointing to index 0.
        int i = 0;

        // Iterate through the array with a pointer 'j' starting from the second element (index 1).
        int j;
        for (j = 1; j < n; j++)
        {
            // Compare the element at index j with the element at index i:
            // If nums[j] is not equal to nums[i], it means we have found a unique element. Increment 'i' by 1 to move the previous pointer one step ahead.
            if (nums[j] != nums[i])
            {
                // Move previous pointer one step ahead.
                i++;

                // Swap the element at index i+1 (next position after the previous pointer) with the element at index j.
                swap(nums[i], nums[j]);
            }
        }

        // Return i + 1, which represents the length of the array without duplicates.
        return i + 1;
    }
};

int main(void)
{
    vector<int> nums{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    // Solution.
    Solution obj;
    int len = obj.removeDuplicates(nums);

    for (int i = 0; i < len; i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}