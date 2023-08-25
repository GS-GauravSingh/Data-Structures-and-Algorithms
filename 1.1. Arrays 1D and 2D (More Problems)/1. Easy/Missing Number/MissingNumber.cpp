#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /* Approach: Simple Maths.

    The goal of the approach is to find a missing number in a given list of numbers. Here's how it works:

    Step 1: We start by figuring out the total number of elements in the given list. Let's call this number 'n'.

    Step 2: We then calculate the sum of all numbers from 0 to 'n'. This sum represents what the total should be if no number is missing. 0 does not make any changes to our sum, so the elements are from 1 to n and to calculate the sum in constant time ,we can use the formula of sum of first n natural numbers.

    Step 3: Next, we iterate through each number in the given list and add them up. This gives us the actual sum of the numbers present in the list.

    Step 4: Finally, we find the difference between the expected sum (step 2) and the actual sum (step 3). This difference corresponds to the missing number.


    Let's consider an example to make it clearer:

    Example:
    Suppose we have a list of numbers: [0, 1, 3, 4, 5].

    The total number of elements in the list is 5, n = 5.

    The expected sum of numbers from 0 to 5 is 0 + 1 + 2 + 3 + 4 + 5 = 15 or n*(n+1)/2 = 5 * (5 + 1) / 2 = 5 * 6 / 2 = 30/2 = 15.

    We iterate through the list and add up the numbers: 0 + 1 + 3 + 4 + 5 = 13.

    The missing number can be found by subtracting the actual sum (13) from the expected sum (15): 15 - 13 = 2.

    In this example, the missing number in the list is 2. By comparing the expected sum with the actual sum, we can identify the missing number.


    Time Complexity: O(n), where 'n' is the size of the nums vector.
    Space Complexity: O(1).
    */
    int missingNumber(vector<int> &nums)
    {

        // size of nums vector.
        int n = nums.size();

        // Now, In the range of [0, n], if all element are present in the 'nums' vector. Then the sum of all element should be equals to the sum of 'n' natural number i.e., n*(n+1)/2.
        int expectedSum = n * (n + 1) / 2;

        // Now, calculate the sum of element present in the nums vector.
        int sumOfEle = 0;
        for (auto i : nums)
            sumOfEle += i;

        // Now, only single element is missing, (sum - sumOfEle) is that missing number.
        return (expectedSum - sumOfEle);
    }
};

int main(void)
{
    vector<int> nums{3, 0, 1};

    // Solution.
    Solution obj;
    cout << obj.missingNumber(nums);
    return 0;
}