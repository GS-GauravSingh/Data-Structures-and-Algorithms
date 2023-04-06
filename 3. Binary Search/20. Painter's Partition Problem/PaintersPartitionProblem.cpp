#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
    bool isPossible(vector<int> &board, int k, int mid)
    {
        int boardSum = 0;
        int paintersCount = 1;

        for (int i = 0; i < board.size(); i++)
        {
            if ((boardSum + board[i]) <= mid)
            {
                boardSum += board[i];
            }
            else
            {

                paintersCount++;

                if (paintersCount > k || board[i] > mid)
                {
                    return false;
                }

                boardSum = board[i];
            }
        }

        return true;
    }

public:

    // Time Complexity :- O(n * log(n)).
    // Space Complexity :- O(1).
    int paintersProblem(vector<int> &board, int k)
    {
        int sum = 0, ans = 0;
        for (int i = 0; i < board.size(); i++)
        {
            sum += board[i];
        }

        int low = 0, high = sum;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (isPossible(board, k, mid))
            {
                ans = mid;

                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};

int main()
{
    vector<int> board = {10, 20, 30, 40};
    int k = 2;

    Solution S;

    cout << S.paintersProblem(board, k);
}