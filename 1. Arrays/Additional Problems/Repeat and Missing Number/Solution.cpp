#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
    /* Brute Force Approach: Using Nested Loops: For each number between 1 to N, we will try to count the occurrence in the given array using linear search. And the element with occurrence as 2 will be the repeating number and the number with 0 occurrences will be the missing number. */
    // Time Complexity: O(n^2), where 'n' is the size of the 'nums' vector.
    // Space Complexity: O(1).
    pair<int, int> repeatAndMissingNumber_BruteForce(vector<int> &nums)
    {
        // Size of 'nums' vector.
        int n = nums.size();

        // variables to store repeating and missing number.
        int repeating = -1, missing = -1;

        // Each number in the array are in the range of [1, N] both inclusive. So, run a loop from 1 to N and count the occurence of each element and the element with occurrence as 2 will be the repeating number and the number with 0 occurrences will be the missing number.
        for (int i = 1; i <= n; i++)
        {
            // variable to count the occurences of given number.
            int occ = 0;

            // count the occurence of 'i' in the array.
            for (int j = 0; j < n; j++)
            {
                if (nums[j] == i)
                {
                    occ++;
                }
            }

            // If occ = 2, then 'i' is a repeating number.
            if (occ == 2)
            {
                repeating = i;
            }

            // If occ = 0, then 'i' is the missing number.
            else if (occ == 0)
            {
                missing = i;
            }

            // If repeating and missing both != -1, it means we found both the numbers, so break the loop.
            if (repeating != -1 && missing != -1)
            {
                break;
            }
        }

        // return final answer.
        return {repeating, missing};
    }

    /* Better Approach: Using Hash array: Instead of counting the occurrences every time, using the hashing technique, we will store the frequency of each element between 1 to N. Now, the element with frequency 2 will be the repeating number and the element with frequency 0 will be the missing number. */
    // Time Complexity: O(n) for storing frequency of each element in the 'hash' array + O(n) for finding repeating and missing number, where 'n' is the size of the 'nums' vector.
    // Space Complexity: O(n), space used by 'hash' array.
    pair<int, int> repeatAndMissingNumber_Better(vector<int> &nums)
    {
        // Size of 'nums' vector.
        int n = nums.size();

        // variables to store repeating and missing number.
        int repeating = -1, missing = -1;

        // Hash Array.
        // Values in array are in the range of [1, N] both inclusive. So declare hash array of size 'n+1' and initialize it with 0.
        vector<int> hash(n + 1, 0);

        // Store the frequency of each element in 'hash' array.
        for (int i = 0; i < n; i++)
        {
            int element = nums[i];
            hash[element]++;
        }

        // Now, traverse the hash array and the element with frequency 2 will be the repeating number and the element with frequency 0 will be the missing number.
        for (int i = 1; i <= n; i++)
        {
            // Repeating Number.
            if (hash[i] == 2)
            {
                repeating = i;
            }

            // Missing Number.
            else if (hash[i] == 0)
            {
                missing = i;
            }

            // If repeating and missing both != -1, it means we found both the numbers, so break the loop.
            if (repeating != -1 && missing != -1)
            {
                break;
            }
        }

        // return final answer.
        return {repeating, missing};
    }

    /* Optimized Approach: Using Mathematics: The idea is to convert the given problem into mathematical equations. Since we have two variables i.e. missing and repeating, we will try to form two linear equations. And then we will find the values of two variables using those equations.

    Example:
    Input Array:[4, 3, 6, 2, 1, 1]
    Output:[1, 5]

    Now, Assume that the repeating number is 'X' and the missing number is 'Y'.
    X --> Repeating Number.
    Y --> Missing Number.

    Creating 1st Equation:
    -------------------------

    Step 1: In order to creating 1st equation, what we have to do is, just sum up all the element from 1 to n and you can easily calculate this using the formula of sum of first 'n' natural numbers i.e., n*(n+1)/2.

                                            Sn = n * (n + 1) / 2.

    Step 2: Now, sum up all the element of given array. Let’s say, S = the summation of all the elements in the given array.

    Step 3: Subtract 'S' with 'Sn'.

    Now, for better understanding, I am writing the above steps in single line.

    Sum of all elements of input array (S)         -        Sum of all elements from 1 to N (Sn)
    (4 + 3 + 6 + 2 + 1 + 1)                    -            (1 + 2 + 3 + 4 + 5 + 6)

    Opening the brackets:
    4 + 3 + 6 + 2 + 1 + 1    - 1 - 2 - 3 - 4 - 5 - 6

    Now, let's cancel out the terms:

    -1 will cancel +1
    -2 will cancel +2
    -3 will cancel +3
    -4 will cancel +4
    -6 will cancel +6

    After canceling out the terms, we left with +1 and -5, because 1 is repeating twice and +5 is missing that's why -5 doesn't cancel anything.

    (1 - 5) = -4, (1-5) will give us -4 and if you carefully observe in (1 - 5), 1 is actually your repeating number and 5 is your missing numbers.

    So, In our above assumptions,
    X --> Repeating Number.
    Y --> Missing Number.

    From this (1 - 5), we can say that:
                                (X - Y) = -4.   ------------- Equation 1.

    And (S - Sn) = -4, or (S - Sn) = (X - Y).

    Now, yu have this equation: (X - Y) = -4. and we have to find the value of x and y, but using only single equation we cannot find the value of x and y. So, we need 1 more equation to solve this.

    Creating 2nd Equation:
    -------------------------

    Step 1: In order to creating 2nd equation, what we have to do is, just sum up the squares of all the element from 1 to n and you can easily calculate this using the formula of sum of squares of first 'n' natural numbers i.e., (n*(n+1)*(2n+1))/6.

                                                S2n = (n * (n+1) * (2n+1) ) / 6

    Step 2: Now, sum up the squares of all the element of given array. Let’s say, S2 = the summation of squares of all the elements in the given array.

    Step 3: Subtract 'S2' with 'S2n'.

    Now, for better understanding, I am writing the above steps in single line.

    Sum of squares of all elements of input array (S2)         -        Sum of squares of all elements from 1 to N (S2n)
    (4^2 + 3^2 + 6^2 + 2^2 + 1^2 + 1^2)                    -            (1^2 + 2^2 + 3^2 + 4^2 + 5^2 + 6^2)

    Opening the brackets:
    4^2 + 3^2 + 6^2 + 2^2 + 1^2 + 1^2                    - 1^2 - 2^2 - 3^2 - 4^2 - 5^2 - 6^2

    Now, let's cancel out the terms:
    -1^2 will cancel +1^2
    -2^2 will cancel +2^2
    -3^2 will cancel +3^2
    -4^2 will cancel +4^2
    -6^2 will cancel +6^2

    After canceling out the terms, we left with +1^2 and -5^2.

    (1^2 - 5^2) => (1 - 25) = -24, (1^2 - 5^2) will give us -24 and if you carefully observe in (1^2 - 5^2), 1 is actually your repeating number and 5 is your missing numbers.

    So, In our above assumptions,
    X --> Repeating Number.
    Y --> Missing Number.

    From this (1^2 - 5^2), we can say that:
                                (X^2 - Y^2) = -24.

    And (S2 - S2n) = -24, or (S2 - S2n) = (X^2 - Y^2).


    Solving this (X^2 - Y^2) = -24 equation:
    (X^2 - Y^2) = -24.
    (X + Y)(X - Y) = -24      [ (a^2 - b^2) = (a + b)(a-b) ]
    (X + Y) -4 = -24      [ (X - Y) = -4.   ------------- From Equation 1. ]
    (X + Y) = -24 / -4
    (X + Y) = 6             [ -24 / -4 = 6 ]

    (X + Y) = 6      ------------------- Equation 2.

    -------------------------- Solving Both Equations ----------------------------------------
    (X - Y) = -4.   -------------------- Equation 1.
    (X + Y) = 6     -------------------- Equation 2.

                                        X - Y = -4.
                                        X + Y = 6
                                    -----------------
                                        2X    = 2
                                        X = 2 / 2
                                        X = 1. We got the repeating number.

    We got X = 1, placing the value of X in above equations.
    (1 + Y) = 6   [ X = 1 ]
    Y = 6 - 1
    Y = 5. We got the missing number.

    So, X = 1 and Y = 5.
    */

    // Time Complexity: O(n), where 'n' is the size of the 'nums' vector.
    // Space Complexity: O(1).
    pair<int, int> repeatAndMissingNumber_Optimized(vector<int> &nums)
    {
        // Size of 'nums' vector.
        int n = nums.size();

        // variables to store repeating and missing number.
        int repeating = -1, missing = -1;

        // For equation 1, we need two things,
        // 1. Sum of all elements from 1 to n (Sn).
        long long Sn = n * (n + 1) / 2;

        // 2. Sum of all elements of input array (S).
        long long S = 0;
        for (int i = 0; i < n; i++)
        {
            S += nums[i];
        }

        // For equation 2, we need two things,
        // 1. Sum of squares of all elements from 1 to n (S2n).
        long long S2n = (n * (n + 1) * (2 * n + 1)) / 6;

        // 2. Sum of squares of all elements of input array (S2).
        long long S2 = 0;
        for (int i = 0; i < n; i++)
        {
            S2 += ((long long)nums[i] * (long long)nums[i]);
        }

        // Now, equation 1: (S - Sn) = (X - Y), lets call (X - Y) as value_1.
        // S - Sn = value_1.
        long long value_1 = S - Sn; // X - Y

        // Now, equation 2: (S2 - S2n) = (X^2 - Y^2), lets call (X^2 - Y^2) as value_2.
        // S2 - S2n = value_2.
        long long value_2 = S2 - S2n;
        value_2 = value_2 / value_1; // X + Y

        // Now, we have to solve both the equations.
        long long X = (value_1 + value_2) / 2;
        long long Y = X - value_1;

        return {(int)X, (int)Y};
    }

public:
    /*
    Question: You are given a read-only array of 'N' integers and values in array are in the range of [1, N] both inclusive. Each integer in the array appears exactly once except 'A' which appears twice and 'B' which is missing. The task is to find the repeating and missing numbers 'A' and 'B' where 'A' repeats twice and 'B' is missing.

    Note that in your output A should precede B.

    Example:
    Input:[3 1 2 5 3]
    Output:[3, 4]

    Explanation: Repeating numbers is 3, 3 appears twice in the array: A = 3,
    and Missing Number is 4: B = 4.
    */

    pair<int, int> repeatAndMissingNumber(vector<int> &nums)
    {
        // // Brute Force Approach.
        // return repeatAndMissingNumber_BruteForce(nums);

        // // Better Approach.
        // return repeatAndMissingNumber_Better(nums);

        // Optimized Approach.
        return repeatAndMissingNumber_Optimized(nums);
    }
};

int main(void)
{
    vector<int> nums{3, 1, 2, 5, 3};

    // Solution.
    Solution S;
    auto ans = S.repeatAndMissingNumber(nums);
    cout << "Repeating Number: " << ans.first << ", and Missing Number: " << ans.second << ".";
    return 0;
}