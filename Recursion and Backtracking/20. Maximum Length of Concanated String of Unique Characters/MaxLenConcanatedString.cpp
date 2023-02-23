#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
    /* Method to compare string. */
    bool compare(vector<int> &prevSelectedCharacters, string &currString)
    {
        // checking if the string itself contains repeating character or not.
        vector<int> selfCheck(26, 0);
        for (int i = 0; i < currString.size(); i++)
        {

            // if the string itself contains repeating character, then simply return false.
            if (selfCheck[currString[i] - 'a'] == 1)
            {
                return false;
            }

            // mark the index.
            selfCheck[currString[i] - 'a'] = 1;
        }

        // if the string does not contains any repeating character,
        // then compare current string with the prevoius selected characters.

        // if the current string has character that we already picked in the past, the return false otherwise return true.
        for (int i = 0; i < currString.size(); i++)
        {
            if (prevSelectedCharacters[currString[i] - 'a'] == 1)
            {
                // means, this particular character we had already selected in the past.
                return false;
            }
        }

        return true;
    }

    int solve(int idx, int n, int lengthTillNow, vector<string> &arr, vector<int> &prevSelectedCharacters)
    {
        // Base Case.
        if (idx >= n)
        {
            return lengthTillNow;
        }

        // Recursive Case.
        string currString = arr[idx];

        if (compare(prevSelectedCharacters, currString) == false)
        {
            // it means, there is an overlapping character.
            // So, we can only igonre this string.
            return solve(idx + 1, n, lengthTillNow, arr, prevSelectedCharacters);
        }
        else
        {
            // it means, there is no overlapping character between the current string and the previous selected strings.
            // also current string does not contain any duplicate characters.

            // Now, we have 2 choices, first is to pick the current string and second is to not pick the current string.

            // Picking the ith string.
            for (int i = 0; i < currString.size(); i++)
            {
                // mark the current character.
                prevSelectedCharacters[currString[i] - 'a'] = 1;
            }

            // store the lenth of string.
            lengthTillNow += currString.size();

            // recursive call.
            int option1 = solve(idx + 1, n, lengthTillNow, arr, prevSelectedCharacters);

            // Backtracking step.
            for (int i = 0; i < currString.size(); i++)
            {
                //  undo the changes.
                prevSelectedCharacters[currString[i] - 'a'] = 0;
            }

            lengthTillNow -= currString.size();

            // Not picking the ith string.
            int option2 = solve(idx + 1, n, lengthTillNow, arr, prevSelectedCharacters);

            // return maximum length.
            return max(option1, option2);
        }
    }

public:

    int stringConcatenation(vector<string> &arr)
    {
        vector<int> prevSelectedCharacters(26, 0);
        return solve(0, arr.size(), 0, arr, prevSelectedCharacters);
    }
};

int main()
{
    vector<string> arr = {"cha", "r", "act", "ers"};

    Solution S;

    cout << S.stringConcatenation(arr);
}