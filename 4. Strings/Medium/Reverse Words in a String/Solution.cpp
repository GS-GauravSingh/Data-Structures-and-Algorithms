#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    /* Method to remove Leading and Trailing Spaces from the string. */
    // Time Complexity: o(n), where 'n' is the length of the string.
    // Space Complexity: O(1).
    void removeLeadingAndTrailingSpaces(string &str)
    {
        // size of the string.
        int n = str.length();

        // Checking for Leading Spaces.
        int i = 0;
        if (str[i] == ' ')
        {
            // Remove all leading Space.
            while (str[i] == ' ')
            {
                i++;
            }
            // After the above loop end, our 'i' pointer is pointing to the first character of the string.
            // Erase all the leading spaces.
            /*
            The erase method of the std::string class takes either one or two parameters:

            1. Starting Position (index): The index of the character in the string where the erasing should start. This parameter is required.

            2. Count (optional): The number of characters to erase from the starting position. If this parameter is not provided, the erase method will remove all characters from the starting position to the end of the string.
            */
            str.erase(0, i);

            // Now, after removing the leading space from the string, the length of the string gets changed.
            // So, we have to update the length of the string.
            n = str.length();
        }

        // Checking for Trailing Spaces.
        if (str[n - 1] == ' ')
        {
            // Remove all trailing Space.
            int j = n - 1;
            while (str[j] == ' ')
            {
                j--;
            }
            // After the above loop end, our 'j' pointer is pointing to the last character of the string.
            // Erase all the trailing spaces from j+1 to end.

            /*
            The erase method of the std::string class takes either one or two parameters:

            1. Starting Position (index): The index of the character in the string where the erasing should start. This parameter is required.

            2. Count (optional): The number of characters to erase from the starting position. If this parameter is not provided, the erase method will remove all characters from the starting position to the end of the string.
            */
            str.erase(j + 1);

            // Now, after removing the trailing space from the string, the length of the string gets changed.
            // So, we have to update the length of the string.
            n = str.length();
        }
    }

    /* Method to remove extra Spaces in between words. */
    // Time Complexity: o(n), where 'n' is the length of the string.
    // Space Complexity: O(1).
    void removeExtraSpacesInBetweenWords(string &str)
    {
        for (int i = 0; i < str.length() - 1; i++)
        {
            // If there is more then one space, it means we have to remove some extra space, because we need only one space in between words.
            if (str[i] == ' ' && str[i + 1] == ' ')
            {
                // As we need only one space in between words.
                // I am start removing extra spaces from 'i+1'th index.
                int j = i + 1;
                while (str[j] == ' ')
                {
                    j++;
                }

                /*
                The erase method of the std::string class takes either one or two parameters:

                1. Starting Position (index): The index of the character in the string where the erasing should start. This parameter is required.

                2. Count (optional): The number of characters to erase from the starting position. If this parameter is not provided, the erase method will remove all characters from the starting position to the end of the string.
                */
                str.erase(i + 1, j - i - 1);

                // update the 'i' pointer.
            }
        }
    }

public:

    // Time Complexity: o(n), where 'n' is the length of the string.
    // Space Complexity: O(1).
    string reverseWords(string str)
    {
        // Step 1: Remove Leading and Trailing space and also remove space in between words, because we need only one space in between words.
        removeLeadingAndTrailingSpaces(str);
        removeExtraSpacesInBetweenWords(str);

        // Step 2: Reverse the entire string.
        reverse(str.begin(), str.end());

        // Step 3: Reverse Each Word in the string.
        for (int i = 0; i < str.length(); i++)
        {
            int j = i;
            while (j != str.length() && str[j] != ' ')
            {
                j++;
            }

            // After the above loop ends, our 'j' now points to the first character after the word.

            // Reverse the word from index 'i' to index 'j - 1'
            reverse(str.begin() + i, str.begin() + j);

            // Move the 'i' pointer to the next word.
            i = j;
        }

        return str;
    }
};

int main(void)
{
    string str = "          the sky     is     blue          ";

    // Solution.
    Solution obj;
    cout << obj.reverseWords(str);
    return 0;
}