#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Time Compelxity: O(n), where 'n' is the size of the vector 'ratings'.
    // Space Complexity: O(n), space used by auxiliary vector.
    int candy(vector<int> &ratings)
    {

        // Size of Vector.
        int n = ratings.size();

        // vector to store distributed candies.
        // Each child must have at least one candy. So, initializethis vector with 1.
        vector<int> candies(n, 1);

        // First Move from left to right and make sure that Children with a higher rating get more candies than their left neighbors.
        for (int i = 1; i < n; i++)
        {
            // variables.
            int currChildRating = ratings[i];
            int leftNeighborRating = ratings[i - 1];

            // If rating of current child > rating of left neighbor, it means current child must have one extra candy from its left neighbor.
            if (currChildRating > leftNeighborRating)
            {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Now, Move from right to left and make sure that Children with a higher rating get more candies than their right neighbors.
        for (int i = n - 2; i >= 0; i--)
        {
            // variables.
            int currChildRating = ratings[i];
            int rightNeighborRating = ratings[i + 1];

            // If rating of current child > rating of right neighbor, it means current child must have one extra candy from its right neighbor.
            if (currChildRating > rightNeighborRating)
            {
                // If the current child (having more ratings than its right neighbor) already has more candies as compared to its right neighbor, In this case, we have to do nothing.

                // But, If the current child (having more ratings than its right neighbor) has less number of candies as compared to its right neighbor, then we have to update the candies of the current child.
                if (candies[i] <= candies[i + 1])
                {
                    candies[i] = candies[i + 1] + 1;
                }
            }
        }

        // The distribution is stored in candies vector.
        int ans = 0;
        for (int i : candies)
            ans += i;

        return ans;
    }
};

int main(void)
{
    vector<int> ratings{1, 2, 87, 87, 87, 2, 1};

    // Solution.
    Solution obj;
    cout << obj.candy(ratings);
    return 0;
}