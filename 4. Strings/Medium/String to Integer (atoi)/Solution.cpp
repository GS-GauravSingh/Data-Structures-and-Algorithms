#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string str)
    {

        // Corner Case
        if (str.empty())
        {
            return 0;
        }

        // Length of the string "str".
        int n = str.length();

        // Boolean variable to chack if there is any sign present in the string or not. This determines if the final result is negative or positive respectively.
        bool isNegative = false;

        // Ignoring Leading White Spaces.
        int i = 0;
        while (i < n && str[i] == ' ')
        {
            i++;
        }

        // Now, after skipping white spaces, our 'i' pointer is poiting to the sign(-) if present anf if sign is not present, then our 'i' pointer may points to the digit or character.
        // If 'i' pointer pointing to character, then return 0.
        if (str[i] == '-')
        {
            isNegative = true;
            i++;
        }
        else if (str[i] == '+')
        {
            isNegative = false;
            i++;
        }

        // variable to store final answer.
        int result = 0;

        // Store the digits until the non-digit character is found.
        while (i < n && str[i] >= '0' && str[i] <= '9')
        {
            // Converting charactyer digit into integer.
            int digit = str[i] - '0';

            // Check for Overflow.
            // INT_MAX = 2147483647 (10 Digits) and INT_MAX/10 = 214748364.7 => 214748364 (9 Digits).
            // So, if our result has already 9 digits and the digit we are going to append is greater than 7, then is will result in overflow.
            // And if the result has more than 9 digits and if you append one more digits, it will also result in overflow.
            if (result > INT_MAX / 10 || (result == (INT_MAX / 10) && digit > 7))
            {
                return isNegative ? INT_MIN : INT_MAX;
            }

            result = result * 10;
            result = result + digit;

            i++;
        }

        if (isNegative)
        {
            result = -result;
        }
        return result;
    }
};

int main(void)
{
    string str = "42";

    // Solution.
    Solution obj;
    cout << obj.myAtoi(str);

    return 0;
}