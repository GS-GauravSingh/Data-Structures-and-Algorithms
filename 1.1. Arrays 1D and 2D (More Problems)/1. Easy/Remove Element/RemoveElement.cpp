#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /* Brute Force Approach: Store all the element (except those element whose value is equal to val) of nums vector into a separate vector and then store the size of this vector, after that update the nums vector and then return the size.
    But, this approach is not In-Place.

    Time Complexity: O(n) + O(k), where 'n' is the size of the nums vector.
    Space Complexity: O(n), space used by 'aux' vector.
    */
    int removeElement_Brute(vector<int> &nums, int val)
    {

        // Size of nums vector.
        int n = nums.size();

        // Storing all element (except for those element whose value is equal to val).
        vector<int> aux;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != val)
            {
                aux.push_back(nums[i]);
            }
        }

        // Sotre the size of this 'aux' vector, because this vector contains all the 'k' element which are not equal to 'val'.
        int size = aux.size();

        // Now, update the nums vector.
        for (int i = 0; i < size; i++)
        {
            nums[i] = aux[i];
        }

        // return k.
        return size;
    }

    /* Optimal Approach: Using Two-Pointer, Whenever we find any element which is not equal to 'val', in this case, we shift this element to the left of the array.

    Time Complexity: O(n), where 'n' is the size of the nums vector.
    Space Complexity: O(1).
    */
    int removeElement_Optimal(vector<int> &nums, int val)
    {

        // Base Case.
        if (nums.size() == 0)
        {
            return 0;
        }

        // Size of nums vector.
        int n = nums.size();

        // Initialize a pointer 'left' to track the previous/left element.
        // Initialize 'left' with 0. Initially 'left' is pointing to index 0.
        int left = 0;

        // Iterate through the array with a pointer 'right'.
        int right;
        for (right = 0; right < n; right++)
        {
            // Compare the element at index 'right' with the 'val'
            // If nums[right] is not equal to 'val', it means we have found a element which is not equal to val.
            if (nums[right] != val)
            {
                // Swap, Place this element to left.
                swap(nums[left], nums[right]);

                // Increment left.
                left++;
            }
        }

        // Return left, which represents the length of the array.
        return left;
    }
};

int main(void)
{
    vector<int> nums{3, 2, 2, 3};
    int val = 3;

    // Solution.
    Solution obj;
    int len = obj.removeElement_Optimal(nums, val);

    for (int i = 0; i < len; i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}