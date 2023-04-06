#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
    // Basically, we have to generate subset's of size k.

    // Time Complexity :- O(2^n), n is the size of array.
    // Space Complexity :- O(n), recursive stack space.
    void generateAllSubsets(int i, int n, int k, vector<int> &subSet, vector<vector<int>> &powerset)
    {
        // Base Case.
        if (subSet.size() == k)
        {
            powerset.push_back(subSet);
            return;
        }
        if (i == n + 1)
        {
            // if (subSet.size() == k)
            // {
            //     powerset.push_back(subSet);
            //     return;
            // }
            return;
        }


        // Recursive Case.

        // picking the ith element.
        subSet.push_back(i);
        generateAllSubsets(i + 1, n, k, subSet, powerset);

        // Backtracking step.
        // remove the picked element.
        subSet.pop_back();

        // not picking the ith element.
        generateAllSubsets(i + 1, n, k, subSet, powerset);
    }

public:
    vector<vector<int>> combination(int n, int k)
    {
        vector<int> subSet;
        vector<vector<int>> powerset;
        generateAllSubsets(1, n, k, subSet, powerset);
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
    int n = 4;
    int k = 2;
    vector<vector<int>> powerset = S.combination(n, k);
    S.print2D(powerset);
}