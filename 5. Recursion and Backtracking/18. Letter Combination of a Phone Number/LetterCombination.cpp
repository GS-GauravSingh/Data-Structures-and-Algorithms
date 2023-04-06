#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
    void solve(string &digit, string &output, int index, vector<string> &ans, unordered_map<int, string> &mapping)
    {
        // Base Case
        if (index >= digit.length())
        {
            ans.push_back(output);
            return;
        }

        int number = digit[index] - '0';
        string value = mapping[number];

        for (int i = 0; i < value.length(); i++)
        {
            output.push_back(value[i]);
            solve(digit, output, index + 1, ans, mapping);
            output.pop_back();
        }
    }

public:
    // Time Complexity :- O(3^n), n is the length of the string.
    // Space Complexity :- O(n), recursive stack space.
    vector<string> letterCombinations(string digits)
    {
        if (digits.length() == 0)
            return {};

        vector<string> ans;
        string output = "";
        int index = 0;

        unordered_map<int, string> mapping;
        mapping[2] = "abc";
        mapping[3] = "def";
        mapping[4] = "ghi";
        mapping[5] = "jkl";
        mapping[6] = "mno";
        mapping[7] = "pqrs";
        mapping[8] = "tuv";
        mapping[9] = "wxyz";

        solve(digits, output, index, ans, mapping);
        return ans;
    }
};

int main()
{
    string digits = "23";

    Solution S;
    vector<string> ans = S.letterCombinations(digits);
    for (string str : ans)
    {
        cout << str << " ";
    }
}