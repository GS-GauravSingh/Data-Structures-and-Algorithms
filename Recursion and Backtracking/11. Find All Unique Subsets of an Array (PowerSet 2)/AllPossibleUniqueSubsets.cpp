#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
    // Time Complexity :- O(n * 2^n), n is the size of array.
    // Space Complexity :- O(n), recursive stack space.
    void generateAllSubsets(int i, int n, vector<int> &arr, vector<int> &subSet, vector<vector<int>> &powerset)
    {
        // Base Case.
        if (i >= n)
        {
            powerset.push_back(subSet);
            return;
        }

        // Recursive Case.

        // picking the ith element.
        subSet.push_back(arr[i]);
        generateAllSubsets(i + 1, n, arr, subSet, powerset);

        // Backtracking step.
        // remove the picked element.
        subSet.pop_back();

        // not picking the ith element.
        // skipping duplicates.
        while (i + 1 < n && arr[i + 1] == arr[i])
        {
            i++;
        }

        generateAllSubsets(i + 1, n, arr, subSet, powerset);
    }

public:
    vector<vector<int>> powerSet(vector<int> &arr)
    {
        // sort the array. So, that all duplicates will come together.
        sort(arr.begin(), arr.end());

        vector<int> subSet;
        vector<vector<int>> powerset;
        generateAllSubsets(0, arr.size(), arr, subSet, powerset);
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
    vector<int> arr = {1, 2, 2};

    Solution S;

    vector<vector<int>> powerset = S.powerSet(arr);
    S.print2D(powerset);
}