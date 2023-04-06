#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
    /*
    Find all valid combinations of k numbers that sum up to end such that the following conditions are true:
        1. Only numbers 1 through 9 are used.
        2. Each number is used at most once.
    */

    // Time Complexity :- O(2^n)
    // Space Complexity :- O(n), recursive stack space.
    void generateAllSubsets(int i, int k, int target, vector<int> &subSet, vector<vector<int>> &powerset)
    {
        // Base Cases.
        if (target < 0)
        {
            return;
        }

        if (i >= 10)
        {
            if (target == 0)
            {
                if (subSet.size() == k)
                {
                    powerset.push_back(subSet);
                    return;
                }
                else
                {
                    return;
                }
            }
            return;
        }

        // Recursive Case.

        // picking the ith element.
        subSet.push_back(i);
        target -= i;
        generateAllSubsets(i + 1, k, target, subSet, powerset);

        // Backtracking step.
        subSet.pop_back();
        target += i;

        // not picking the ith element.
        generateAllSubsets(i + 1, k, target, subSet, powerset);
    }

public:
    vector<vector<int>> combinationSum3(int k, int target)
    {
        vector<int> subSet;
        vector<vector<int>> powerset;

        generateAllSubsets(1, k, target, subSet, powerset);
        return powerset;
    }

    /* Method to print 2D vector. */
    void print2D(vector<vector<int>> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i].size() == 0)
            {
                cout << "{}\end";
                continue;
            }

            for (int j = 0; j < arr[i].size(); j++)
            {
                cout << arr[i][j] << ' ';
            }
            cout << endl;
        }
    }
};

int main()
{
    Solution S;
    int target = 7;
    int k = 3;
    vector<vector<int>> powerset = S.combinationSum3(k, target);
    S.print2D(powerset);
}