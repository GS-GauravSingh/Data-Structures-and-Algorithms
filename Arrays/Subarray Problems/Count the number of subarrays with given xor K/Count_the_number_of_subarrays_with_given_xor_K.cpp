#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
public:
    /* Brute Force Approach :- generate all subarrays and find the answer */
    // Time Complexity :- o(n^3)
    // Space Complexity :- o(1)
    int subarrayXOR_Approach_1(vector<int> &A, int B)
    {
        // size of vector.
        int n = A.size();

        // variable for storing total number of subarrays having bitwise XOR of all elements equal to B.
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                // variable for calculating the xor of each subarray.
                int xorr = 0;

                for (int k = i; k <= j; k++)
                {
                    xorr = xorr ^ A[k];
                }

                if (xorr == B)
                {
                    count++;
                }
            }
        }
        return count;
    }

    /* Optimizing Above Approach :- Instead of using 3 loops, we can generate all subarrays using nested loops (2 loops). */
    // Time Complexity :- o(n^2)
    // Space Complexity :- o(1)
    int subarrayXOR_Approach_2(vector<int> &A, int B)
    {
        // size of vector.
        int n = A.size();

        // variable for storing total number of subarrays having bitwise XOR of all elements equal to B.
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            // variable for calculating the xor of each subarray.
            int xorr = 0;
            for (int j = i; j < n; j++)
            {
                xorr = xorr ^ A[j];

                if (xorr == B)
                {
                    count++;
                }
            }
        }
        return count;
    }

    /* Optimized Approach :- using prefix sum and hashing. */
    // Time Complexity :- o(n)
    // Space Complexity :- o(n)
    int subarrayXOR_Optimized(vector<int> &A, int B)
    {
        // size of vector.
        int n = A.size();

        // variable for storing total number of subarrays having bitwise XOR of all elements equal to B.
        int count = 0;

        // prefix xor array.
        vector<int> prefix;
        int xorr = 0;
        for (int i = 0; i < n; i++)
        {
            xorr = xorr ^ A[i];
            prefix.push_back(xorr);
        }

        // declare an unordered map to store cumulative xor.
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            if (prefix[i] == B) // if it already becomes equal to B, then increment count
                count++;

            // now, check if (prefix[i] ^ B) is present in map or not
            if (mp.find(prefix[i] ^ B) != mp.end())
            {
                // if yes, then update our answer with it's frequency.
                count += mp[prefix[i] ^ B];
            }

            // store prefix sum in map with it's frequency.
            mp[prefix[i]]++;
        }

        // return our answer
        return count;
    }
};

int main()
{
    vector<int> A = {4, 2, 2, 6, 4};
    int B = 6;

    Solution S;
    cout << S.subarrayXOR_Approach_1(A, B) << endl;
    cout << S.subarrayXOR_Approach_2(A, B) << endl;
    cout << S.subarrayXOR_Optimized(A, B) << endl;
}