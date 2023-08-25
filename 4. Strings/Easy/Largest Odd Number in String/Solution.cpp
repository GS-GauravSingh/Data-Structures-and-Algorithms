#include <bits/stdc++.h>
using namespace std;

class Solution
{
    /* Method to convert string to integer. */
    // Time Complexity: O(n), where 'n' is the length of the string.
    // Space Complexity: O(1).
    long long convertStringToInt(string str)
    {
        long long int number = 0;

        for (int i = 0; i < str.length(); i++)
        {
            number = number * 10;
            number = number + (str[i] - '0');
        }

        return number;
    }

    /* Brute Force Approach: Generale all substrings and then find the maximum length substring that represent odd integer. */
    // Time Complexity: O(n^3), where 'n' is the length of the string.
    // Space Complexity: O(1).
    string largestOddNumber_BruteForce(string num)
    {
        // size of the string.
        int n = num.length();

        // variable to store maximum length.
        int maxLen = 0;

        // variable to store answer.
        string ans = "";

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                // variable to store current substring.
                string temp = "";

                for (int k = i; k <= j; k++)
                {
                    temp.push_back(num[k]);
                }

                // Convert string to int.
                long long number = convertStringToInt(temp);

                // Odd Number.
                if (number & 1)
                {
                    if (temp.length() > maxLen)
                    {
                        ans = temp;
                        maxLen = temp.length();
                    }
                }
            }
        }

        return ans;
    }

    /* Better Approach: Generale all substrings using nested loops and then find the maximum length substring that represent odd integer. */
    // Time Complexity: O(n^2), where 'n' is the length of the string.
    // Space Complexity: O(1).
    string largestOddNumber_Better(string num)
    {
        // size of the string.
        int n = num.length();

        // variable to store maximum length.
        int maxLen = 0;

        // variable to store answer.
        string ans = "";

        for (int i = 0; i < n; i++)
        {
            // variable to store current substring.
            string temp = "";
            for (int j = i; j < n; j++)
            {

                temp.push_back(num[j]);

                // Convert string to int.
                long long number = convertStringToInt(temp);

                // Odd Number.
                if (number & 1)
                {
                    if (temp.length() > maxLen)
                    {
                        ans = temp;
                        maxLen = temp.length();
                    }
                }
            }
        }

        return ans;
    }

    /* Optimized Approach.

    Intution:
    Consider this number => 1234567892, Now, this number contains both odd (1,3,5,7,9) and even (2,4,6,8) numbers in it and this number is an even number and we can say this because the last digit of this number (last digit is 2) is even.

    Now, the observation is, any number that is of any length, that number is even or odd, is identified by the last digit of that number.

    Here's the rule:
    1. If the last digit of a number is even (0, 2, 4, 6, or 8), then the entire number is even.
    2. If the last digit of a number is odd (1, 3, 5, 7, or 9), then the entire number is odd.

    So, if we find the righmost ODD digit in the given string "num", then we can say that the number starting from index 0 to the index of that ODD number is my longest substring that represent odd number.
    */

    // Time Complexity: O(n), where 'n' is the length of the string.
    // Space Complexity: O(1).
    string largestOddNumber_Optmized(string num)
    {
        int rightMostOddIdx = -1;
        for (int i = num.length() - 1; i >= 0; i--)
        {
            int val = num[i] - '0';

            // ODD Digit.
            if (val & 1)
            {
                rightMostOddIdx = i;
                break;
            }
        }

        // if rightMostOddIdx == -1, it means the string "num" contains all even numbers.
        if (rightMostOddIdx == -1)
        {
            return "";
        }

        /*
        The substr method is used to extract a substring from a given string. It takes two parameters:
        1. Starting Index: This parameter specifies the index at which the substring should start. It is a required parameter and is usually a non-negative integer.

        2. Count (Optional): This parameter specifies the number of characters to be extracted from the starting index. It is an optional parameter. If not provided, the substring will include all characters from the starting index to the end of the string.
        */
        return num.substr(0, rightMostOddIdx + 1);
    }

public:
    string largestOddNumber(string num)
    {
        // // Brute Force Solution.
        // return largestOddNumber_BruteForce(num);

        // // Better Approach.
        // return largestOddNumber_Better(num);

        // Optimized Approach.
        return largestOddNumber_Optmized(num);
    }
};

int main(void)
{
    string num = "1234567892";

    // Solution.
    Solution obj;
    cout << obj.largestOddNumber(num);
    return 0;
}