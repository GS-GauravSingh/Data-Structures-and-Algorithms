#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /* Approach: Using Bitwise Xor (^) operator (Constant Space Approach).

    Xor (^) Logic gate:
    X   Y   Result
    1 ^ 1 =   0
    0 ^ 1 =   1
    1 ^ 0 =   1
    0 ^ 0 =   0

    If we observe carefully, 0 ^ 0 = 0 or 1 ^ 1 = 0, it means, xor of 2 same numbers is zero and in this question, all element appear twice except for the one. So, if we perform the xor on all element of array, then element which appears twice, the xor of these element will give 0 and when we xor 0 with that single number, it will give that single number.

    In Short, In the case of the given question where all elements appear twice except for one, XORing all the numbers together will effectively cancel out the pairs, leaving only the XOR value of the single number. XORing 0 with any number gives that number itself.

    So, by XORing all the numbers in the array, the pairs will cancel out, and the final XOR value will be the single number that appears only once.

    Time Complexity: O(n), where 'n' is the size of the nums vector.
    Space Complexity: O(1).
    */
    int singleNumber(vector<int> &nums)
    {
        // Size of nums vector.
        int n = nums.size();

        // Initialize xorr to 0.
        int xorr = 0;

        // Traverse the nums vector.
        for (int i = 0; i < n; i++)
        {
            // XORing all the numbers in the array.
            xorr = xorr ^ nums[i];
        }

        // return answer.
        return xorr;
    }
};

int main(void)
{
    vector<int> nums{4, 1, 2, 1, 2};

    // Solution.
    Solution obj;
    cout << obj.singleNumber(nums);
    return 0;
}