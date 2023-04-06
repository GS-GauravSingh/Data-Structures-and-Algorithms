#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
    void generate(int idx, int n, string &str, vector<string> &allPermutations)
    {
        // Base Case.
        if (idx >= n)
        {
            allPermutations.push_back(str);
            return;
        }

        // Recursive Case.
        for (int i = idx; i < n; i++)
        {
            swap(str[idx], str[i]);

            // recursive call.
            generate(idx + 1, n, str, allPermutations);

            // Backtracking step.
            swap(str[idx], str[i]);
        }
    }

public:
    // Time Complexity :- O(n*n!)
    // Space Complexity :- O(n)
    vector<string> generateAllPermutations(string &str)
    {
        vector<string> allPermutations;
        generate(0, str.length(), str, allPermutations);
        return allPermutations;
    }
};

int main()
{
    string str = "abc";

    Solution S;

    vector<string> ans = S.generateAllPermutations(str);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}