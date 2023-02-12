#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
public:

    /* Approach 1 :- Using hashing. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(n)
    void moreThanNbyk_Approach_1(vector<int> &arr, int n, int k)
    {
        // we have to find those elements that appear more than n/k times.
        int occur = n / k;

        // count the frequency of each element and storing in map.
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++)
        {
            int element = arr[i];
            freq[element]++;
        }

        // Traverse the map and print the element which has frequency more than n/k.
        for (auto i : freq)
        {
            if (i.second > occur)
            {
                cout << i.first << " ";
            }
        }
    }
};

int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 5, 4, 2, 2, 3, 1, 1, 1};
    int k = 4;

    Solution S;
    S.moreThanNbyk_Approach_1(arr, arr.size(), k);
}
