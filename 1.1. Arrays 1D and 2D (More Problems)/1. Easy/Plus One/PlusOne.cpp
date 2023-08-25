#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Time Complexity: O(n), where 'n' is the size of the vector.
    // Space Complexity: O(1).
    vector<int> plusOne(vector<int> &digits)
    {

        // size of vector.
        int n = digits.size();

        // Iterate through the vector in reverse order, starting from the last element, because we perfrom addition from right.
        // Ex: 1 2 8
        //     +   1
        //    -------
        //     1 2 9
        //    -------
        for (int i = n - 1; i >= 0; i--)
        {
            // Check if the current digit digits[i] is equal to 9.

            // If it is equal to 9, set it to 0 because when 9 is incremented, it becomes 10 and we write 0 in our answer and take 1 as carry.
            /*     1
            Ex:    1 9
                   + 1
                  -----
                   2 0
                  -----
            */
            if (digits[i] == 9)
            {
                digits[i] = 0;
            }

            // If the current digit is not equal to 9, increment it by 1 and break out of the loop.
            else
            {
                digits[i]++;
                break;
            }
        }

        // Now, if any test case contains all 9's, Ex: {9, 9, 9}, so our above loop will modify the array like this {0, 0, 0}.
        // So, if the first element of digits array is 0, it means the digits array contains all 9's.
        // In this case, set the first element to 1 and push one 0 into digits array.

        /*         1 1
            Ex:    9 9 9
                     + 1
                   ------
                   0 0 0
                   ------

            digits array after above loop ends: {0, 0, 0}.

            Now, set the first element to 1 and push one 0 into digits array.
            digits: {1, 0, 0, 0}.
            */
        if (digits[0] == 0)
        {
            digits[0] = 1;
            digits.push_back(0);
        }

        // return final answer.
        return digits;
    }
};

int main(void)
{
    vector<int> digits{9, 9, 9};

    // Solution.
    Solution obj;
    vector<int> ans = obj.plusOne(digits);

    for (auto i : ans)
    {
        cout << i;
    }
    return 0;
}