#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
    /* This function checks whether it's possible to allocate books to a given number of students while ensuring that no student receives more than a specified 'limit' of pages. */
    // Time Complexity: O(n), where 'n' is the size of the 'books' vector.
    // Space Complexity: O(1).
    bool canAllocateOrNot(vector<int> &books, int students, int limit)
    {
        int studentCount = 1;
        int pageSum = 0;
        for (int i = 0; i < books.size(); i++)
        {
            if (pageSum + books[i] <= limit)
            {
                pageSum += books[i];
            }
            else
            {
                studentCount++;
                if (studentCount > students || books[i] > limit)
                {
                    return false;
                }
                pageSum = books[i];
            }
        }

        return true;
    }

public:

    // Time Complexity: O(n) for finding low and high + O(n*log(n)) for finding answer.
    // Space Complexity: O(1).
    int allocateBooks(vector<int> &books, int students)
    {
        // size of vector.
        int n = books.size();

        // The minimum number of pages you can allocate to any student is minimum element of array i.e., the book with minimum number of pages.
        // When the number of students is 1, there is only one possible way to allocate the books: all the books are assigned to that single student. In this case, the maximum number of pages assigned to a student is indeed the sum of all the pages in the books.
        
        // So, our search space is from [min_element(book), sum of all pages].
        int low = INT_MAX;
        int high = 0;
        for (int i : books)
        {
            low = min(low, i);
            high += i;
        }

        // variable to store answer.
        int ans = -1;

        // Binary Search.
        while (low <= high)
        {
            // Mid (Maximum number of pages a student can have).
            int mid = low + (high - low) / 2;

            // Now, I am setting a Upper bound, it means I am trying to allocate book in such a way so that the maximum number of pages assigned to a student is 'mid' and if I am able to allocate all the 'n' books to 'm' students with this Upper Bound 'mid', then it is obvious that I am also able to allocate all the 'n' books to 'm' students with Upper Bound greater than 'mid'.
            // And our, task is to minimize this Upper bound, so store this upper bound and move to left half.
            if (canAllocateOrNot(books, students, mid))
            {
                ans = mid;

                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
    }
};

int main(void)
{
    vector<int> books{25, 46, 28, 49, 24};
    int m = 4;

    // Solution.
    Solution obj;
    cout << obj.allocateBooks(books, m);
    return 0;
}