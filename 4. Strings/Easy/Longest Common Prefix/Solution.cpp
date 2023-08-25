#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
public:
    /*
    Approach: Using Sorting.

    Intution: First we Sort the given vector because sort method will sort the given vector of strings in lexicographical order (Lexicographical Order also know as Dictionary Order) and sorting will ensures that the strings with common prefix will be adjacent to each other.

    Example:
    vector<string> strs = {abcdef, abc, abcd, abcde};
    Now, after sorting the above vector, the vector would look like this:
    {abc, abcd, abcde, abcdef}, See, after sorting all the string with common prefix are adjacent to each other.

    Now, we can easily compare the first and last string to find out the common prefix.

    See, the longest common prefix is something which is common in all the elements and when you sort the given vector of strings in lexicographical order, then the strings with common prefix will be adjacent to each other.
    */

    // Time Complexity: O(n log(n)), where 'n' is the size of the vector.
    // Space Complexity: O(1).
    string longestCommonPrefix(vector<string> &strs)
    {
        // Sort the given vector.
        sort(strs.begin(), strs.end());

        // Compare first and last string to find out the common prefix.
        string first = strs[0];
        string last = strs[strs.size() - 1];

        // Pointers to traverse the first and last string.
        int i = 0;
        int j = 0;

        // string to store common prefix.
        string ans = "";

        while (i < first.size() && j < last.size())
        {
            if (first[i] == last[j])
            {
                ans.push_back(first[i]);
                i++;
                j++;
            }
            else
            {
                break;
            }
        }

        return ans;
    }
};

int main(void)
{
    vector<string> strs = {"flower", "flow", "flight"};

    // Solution.
    Solution obj;
    cout << obj.longestCommonPrefix(strs);
    return 0;
}