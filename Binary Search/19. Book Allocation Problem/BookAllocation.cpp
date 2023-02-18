#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
    bool isPossible(vector<int> &books, int students, int mid)
    {
        int pageSum = 0;
        int studentCount = 1;

        for (int i = 0; i < books.size(); i++)
        {
            if ((pageSum + books[i]) <= mid)
            {
                pageSum += books[i];
            }
            else
            {

                studentCount++;

                if (studentCount > students || books[i] > mid)
                {
                    return false;
                }

                pageSum = books[i];
            }
        }

        return true;
    }

public:

    // Time Complexity :- O(n * log(n)).
    // Space Complexity :- O(1).
    int allocateBooks(vector<int> &books, int students)
    {
        int sum = 0, ans = 0;
        for (int i = 0; i < books.size(); i++)
        {
            sum += books[i];
        }

        int low = 0, high = sum;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (isPossible(books, students, mid))
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
    vector<int> books = {10, 20, 30, 40};
    int students = 2;

    Solution S;

    cout << S.allocateBooks(books, students);
}