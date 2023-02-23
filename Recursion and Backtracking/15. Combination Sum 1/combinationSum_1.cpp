#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
    // generate the subset whose summation is equal to target.
    // The same number may be chosen from candidates an unlimited number of times.

    // Time Complexity :- O(2^n), n is the size of array.
    // Space Complexity :- O(n), recursive stack space.
    void generateAllSubsets(int i, int n, vector<int> &candidate, int sum, int target, vector<int> &subSet, vector<vector<int>> &powerset)
    {
        // Base Casees.
        if (target < 0)
        {
            return;
        }

        if (sum == target)
        {
            powerset.push_back(subSet);
            return;
        }

        if (sum > target)
        {
            return;
        }

        if (i >= n)
        {
            return;
        }

        // Recursive Case.

        // picking the ith element.
        subSet.push_back(candidate[i]);
        sum += candidate[i];
        generateAllSubsets(i, n, candidate, sum, target, subSet, powerset);

        // Backtracking step.
        // remove the picked element from subset and sum.
        subSet.pop_back();
        sum -= candidate[i];

        // not picking the ith element.
        generateAllSubsets(i + 1, n, candidate, sum, target, subSet, powerset);
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidate, int target)
    {
        vector<int> subSet;
        vector<vector<int>> powerset;

        generateAllSubsets(0, candidate.size(), candidate, 0, target, subSet, powerset);
        return powerset;
    }

    /* Method to print 2D vector. */
    void print2D(vector<vector<int>> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i].size() == 0)
            {
                cout << "{}\n";
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
    vector<int> candidate = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> powerset = S.combinationSum(candidate, target);
    S.print2D(powerset);
}