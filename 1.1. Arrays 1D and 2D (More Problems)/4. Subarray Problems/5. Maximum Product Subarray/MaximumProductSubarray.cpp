#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
public:
    /* Brute Force Approach: generating all subarrays.  */
    // Time Complexity: O(n^3), where 'n' is the size of the nums vector.
    // Space Complexity: O(1)
    int maxProduct_BruteForce(vector<int> &nums)
    {

        // size of array.
        int n = nums.size();

        // variable for storing maximum product subarray..
        int maxP = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                // variable for calculating the product of each subarray.
                int product = 1;
                for (int k = i; k <= j; k++)
                {
                    product *= nums[k];
                }

                // maximum product subarray.
                maxP = max(maxP, product);
            }
        }

        return maxP;
    }

    /* Better Approach: Instead of using 3 loops, we can generate all subarrays using nested loops (2 loops).  */
    // Time Complexity: O(n^2), where 'n' is the size of the nums vector.
    // Space Complexity: O(1)
    int maxProduct_Better(vector<int> &nums)
    {

        // size of array.
        int n = nums.size();

        // variable for storing maximum product subarray..
        int maxP = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            // variable for calculating the product of each subarray.
            int product = 1;
            for (int j = i; j < n; j++)
            {

                product *= nums[j];

                // maximum product subarray.
                maxP = max(maxP, product);
            }
        }

        return maxP;
    }

    /* Optimized Approach: Now, this problem has 2 optimal approaches, one of them is purely observation based and another is using modified kadanes algorithm.

    Now, the observation based approach is more intutive, so we solve this qeustion using this approach.

    Let's talk about this Observation based approach:

    ------------------------------------------- Observation 1st ----------------------------------------------------------------------
    Observation 1st: What if the array has all positive (+ve) elements?
    Now, in this case, our answer will be the product of entire array, because in case of all +ve elements, the subarray that gives me maximum produvt is the entire array.

    ------------------------------------------- Observation 2nd ----------------------------------------------------------------------
    Observation 2nd: What is the array has even number of negative (-ve) elements and rest of all are positives (+ve)?
    Now, in this case, our answer will again be the product of entire array.

    Reason: The reasoning behind this is that when you multiply an even number of negative elements together, the result will be positive. Additionally, multiplying positive elements together will also result in a positive product. Therefore, in this scenario, the maximum product subarray will include all the positive elements and the even number of negative elements, resulting in a positive product.

    For example, consider the array: [2, 3, -2, 4, -1, 6]
    The maximum product subarray will be the entire array: 2 * 3 * -2 * 4 * -1 * 6 = 144.

    ------------------------------------------- Observation 3rd ----------------------------------------------------------------------
    Observation 3rd: What is the array has odd number of negative (-ve) elements and rest of all are positives (+ve)?
    Now, in this case, our answer will not be the product of entire array because when you multiply an odd number of negative elements together, the result will be a negative element.

    For example, consider the array: [2, 3, -1, 6]
    Product of entire subarray is: -36.

    Note: We are talking about product and we get the maximum product when we multiply more elements together and in our case, we need subarray with maximum product, so we need to multiple more element and elements should be in contiguous manner (Subarray).

    How to tackle odd number of negatives?
    So, what we can do is, we can remove 1 negative element and removal of 1 negative out of odd number of negatives will leave us with even number of negatives, hence the idea is to remove 1 negative element.

    Now, we just have to identify, on removing which negative element will give us the maximum product. Let's find out with the help of an example:

    Example array: {2, 3, -1, 4, -6, 3, -2, 6}

    Case 1: Probably we can ignore -1, if we ignore -1, we left with 2 subarrays:
    1st subarray: {2, 3} -> left subarray: Product = 6.
    2nd subarray: {4, -6, 3, -2, 6} -> right subarray: Product = 864, and this will give maximum product in this case 1.

    Case 2: Probably we can ignore -2, if we ignore -2, we left with 2 subarrays:
    1st subarray: {2, 3, -1, 4, -6, 3} -> left subarray: Product = 432, and this will give maximum product in this case 2.
    2nd subarray: {6} -> right subarray: Product = 6.

    Case 3: Probably we can ignore -6. if we ignore -6, we left with 2 subarrays:
    1st subarray: {2, 3, -1, 4} -> left subarray: Product = -24, and this will give maximum product in this case 3.
    2nd subarray: {3, -2, 6} -> right subarray: Product = -36.

    Now, from all of the above 3 cases, I can say that, whatever the negative element you ignore, to find the maximum product subarray you need 2 things,
    1st: The product of all elements before the number (negative number) you are ignoring.
    2nd: The product of all elements after the number (negative number) you are ignoring.

    and Maximum Product Subarray = max(1st, 2nd).

    Now, Just 1 case is missing and the case is: What If 0's are present in the array: and in this case multipling all the elements together will not gives us the maximum product because the product of multiply all element together will gives us 0.

    Example: {-2, 3, 4, -1, 0, -2, 3, 4, 0, 4, 6, -1, 4}
    Now can I say that, no matter how many number you are taking, if there is a 0, then the multiplication will be 0, so taking a 0 doesn't make sense.

    Now, we can use 0 and a break point, we can use 0 to divide the arrays like this:
    In the above example, we can divide the above array into 3 seperate subarrays:
    1st subarray: {-2, 3, 4, -1}
    2nd subarray: {-2, 3, 4}
    3rd subarray: {4, 6, -1, 4}

    And now we can easily apply the above logic on all the 3 subarrays and return the maximum among them.
    */

    // Time Complexity :- O(n), where 'n' is the size of the nums vector.
    // Space Complexity :- O(1)
    int maxProduct_Optimized(vector<int> &nums)
    {
        // size of array.
        int n = nums.size();

        // variable to check whether 0 is present or not.
        bool zeroPresent = false;

        // Variable to compute prefix Product.
        int prefixProduct = 1;

        // variable to store maximum product.
        int maxProduct = INT_MIN;

        // Traverse of 0 to n and find the maximum product.
        for (int i = 0; i < n; i++)
        {
            // Break Point.
            if (nums[i] == 0)
            {
                prefixProduct = 1;
                zeroPresent = true;
                continue;
            }

            // Compute Prefix Product.
            prefixProduct *= nums[i];

            // Store the maximum product.
            maxProduct = max(maxProduct, prefixProduct);
        }

        // Variable to compute suffix Product.
        int suffixProduct = 1;

        // Traverse of n to 0 and find the maximum product.
        for (int i = n - 1; i >= 0; i--)
        {
            // Break Point.
            if (nums[i] == 0)
            {
                suffixProduct = 1;
                continue;
            }

            // Compute Suffix Product.
            suffixProduct *= nums[i];

            // Store the maximum product.
            maxProduct = max(maxProduct, suffixProduct);
        }

        // return maximum product.
        if (zeroPresent)
        {
            // Why I am returning this, Dry-run this approach on below example.
            // Example  TestCase: {-1, 0, -2}.
            return max(0, maxProduct);
        }

        return maxProduct;
    }
};

int main()
{
    vector<int> nums = {2, 3, -2, 4};

    // Solution.
    Solution S;
    cout << S.maxProduct_BruteForce(nums) << endl;
    cout << S.maxProduct_Better(nums) << endl;
    cout << S.maxProduct_Optimized(nums);
}