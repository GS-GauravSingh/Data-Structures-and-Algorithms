#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
    /* Recursive Method to find the maximum merit points the ninja can attain in N Days. */
    // Time Complexity: O(2^n), n is the number of days.
    // Space Complexity: O(n), recursive stack space.
    int solveRecursive(int day, int lastActivityPerformed, vector<vector<int>> &points)
    {
        // Base Case.
        if (day == 0)
        {
            // When day = 0, it means from here you cannot move ahead i.e., you cannot go to day -1, day -2 because these are invalid.

            // Now, when you reached day 0 it is 100% sure that you reached day 0 from day 1 and you must have performed some task/activity on day 1, so you cannot perform that same activity again on day 0 (Reason: we cannot perform same activity on consecutive days).

            // Now, on day 0, except for that activity that the ninja performed on day 1, from the rest of the activities, perform that activity that gives us maximum merit points.

            // variable to store maximum merit points among the rest of the activities.
            int maxPoints = 0;

            for (int activity = 0; activity <= 2; activity++)
            {
                // We cannot perform same activity on consecutive days.
                if (activity != lastActivityPerformed)
                {
                    maxPoints = max(maxPoints, points[day][activity]);
                }
            }

            // return the maximum merit point.
            return maxPoints;
        }

        // Recursive Case.

        // variable to store maximum merit points among the rest of the activities.
        int maxPoints = 0;

        for (int activity = 0; activity <= 2; activity++)
        {
            // We cannot perform same activity on consecutive days.
            if (activity != lastActivityPerformed)
            {
                int currPoints = points[day][activity] + solveRecursive(day - 1, activity, points);
                maxPoints = max(maxPoints, currPoints);
            }
        }

        // return the maximum merit point.
        return maxPoints;
    }

    /* Optimizing the above Recursive Code using Top-Down Dynamic Programming (AKA Memoization). */

    /* In the top-down approach, we start with the original problem and break it down
    into smaller subproblems. We then recursively solve each subproblem, storing
    the result in a cache or table as we go. When we encounter a subproblem that
    we've already solved, we simply look up the answer in the cache instead of
    recomputing it. This approach is also known as memoization. */

    // Time Complexity: O(n), n is the number of days.
    // Space Complexity: O(n) + O(n*4), recursion stack space(O(N)) and a 2D array (again O(N*4)). Therefore total space complexity will be O(N) + O(N) ≈ O(N)
    int solveMemoized(int day, int lastActivityPerformed, vector<vector<int>> &points, vector<vector<int>> &dp)
    {
        // Base Case.
        if (day == 0)
        {
            // When day = 0, it means from here you cannot move ahead i.e., you cannot go to day -1, day -2 because these are invalid.

            // Now, when you reached day 0 it is 100% sure that you reached day 0 from day 1 and you must have performed some task/activity on day 1, so you cannot perform that same activity again on day 0 (Reason: we cannot perform same activity on consecutive days).

            // Now, on day 0, except for that activity that the ninja performed on day 1, from the rest of the activities, perform that activity that gives us maximum merit points.

            // variable to store maximum merit points among the rest of the activities.
            int maxPoints = 0;

            for (int activity = 0; activity <= 2; activity++)
            {
                // We cannot perform same activity on consecutive days.
                if (activity != lastActivityPerformed)
                {
                    maxPoints = max(maxPoints, points[day][activity]);
                }
            }

            // store the answer of this subproblem and then return the maximum merit point.
            return dp[day][lastActivityPerformed] = maxPoints;
        }

        // Recursive Case.

        /* Now, Before Calling recursion, first check whether this subproblem is an overlapping subproblem or not because if this subproblem is an overlapping subproblem (repetative subproblem), in this case, the answer of this subproblem is stored in our 'dp' array. */
        if (dp[day][lastActivityPerformed] != -1)
        {
            return dp[day][lastActivityPerformed];
        }

        // variable to store maximum merit points among the rest of the activities.
        int maxPoints = 0;

        for (int activity = 0; activity <= 2; activity++)
        {
            // We cannot perform same activity on consecutive days.
            if (activity != lastActivityPerformed)
            {
                int currPoints = points[day][activity] + solveMemoized(day - 1, activity, points, dp);
                maxPoints = max(maxPoints, currPoints);
            }
        }

        // store the answer of this subproblem and then return the maximum merit point.
        return dp[day][lastActivityPerformed] = maxPoints;
    }

    /* Optimizing the above DP Memoized Code using Bottom-Up Dynamic Programming (AKA Tabulation). */

    /* In the bottom-up approach, we start with the smallest subproblems and work
    our way up to the original problem. We store the results of each subproblem in
    a table or cache and use those results to solve larger subproblems. By the time
    we get to the original problem, we've already solved all the subproblems we
    need and can simply look up the answer in the table. This approach is also
    known as tabulation. */

    // Time Complexity: O(n*4*3) ≈ O(n) , n is the number of days.
    // Space Complexity: O(n*4), size of dp array.
    int solveTabulized(int n, vector<vector<int>> &points)
    {
        // 'dp' array/vector to store and compute the answer of subproblems.
        vector<vector<int>> dp(n, vector<int>(4, 0));

        // As we know in Tabulation, we have to convert the Recursive Memoization code to an iterative code.

        // So, first we need to convert the base case.

        // If you observe carefull, you can easily fill the 0th row of dp array, where 0th row represents day 0. So when you are at the day 0 it is 100% sure that you reached day 0 from day 1 and you must have performed some task/activity on day 1, so you cannot perform that same activity again on day 0 (Reason: we cannot perform same activity on consecutive days).

        // So, if you performed task 0 on day 1, it means you cannot perform task 0 on day 0, it means except for task 0, we can perform task 1 or task 2 and our answer is the max(points[task 1], points[task 2]).
        // So, dp[0][0] = max(points[task 1], points[task 2]).
        dp[0][0] = max(points[0][1], points[0][2]);

        // So, if you performed task 1 on day 1, it means you cannot perform task 1 on day 0, it means except for task 1, we can perform task 0 or task 2 and our answer is the max(points[task 0], points[task 2]).
        // So, dp[0][1] = max(points[task 0], points[task 2]).
        dp[0][1] = max(points[0][0], points[0][2]);

        // So, if you performed task 2 on day 1, it means you cannot perform task 2 on day 0, it means except for task 2, we can perform task 0 or task 1 and our answer is the max(points[task 0], points[task 1]).
        // So, dp[0][2] = max(points[task 0], points[task 1]).
        dp[0][2] = max(points[0][0], points[0][1]);

        // dp[0][3], where 3 means no task is perfromed yet. So, dp[0][3] = max(points[task 0], points[task 1], points[task 2]).
        dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

        for (int day = 1; day < n; day++)
        {
            for (int lastActivityPerformed = 0; lastActivityPerformed < 4; lastActivityPerformed++)
            {
                for (int activity = 0; activity <= 2; activity++)
                {
                    // We cannot perform same activity on consecutive days.
                    if (activity != lastActivityPerformed)
                    {
                        int currPoints = points[day][activity] + dp[day - 1][activity];
                        dp[day][lastActivityPerformed] = max(dp[day][lastActivityPerformed], currPoints);
                    }
                }
            }
        }

        return dp[n - 1][3];
    }

    /* Space Optimizing the above DP Tabulation code. */
    // Using 1D array instead of 2D array.

    // Time Complexity: O(n*4*3) ≈ O(n) , n is the number of days.
    // Space Complexity: O(4), size of dp array.
    int solveSpaceOptimized(int n, vector<vector<int>> &points)
    {
        // 'dp' array/vector to store and compute the answer of subproblems.
        vector<int> dp(4, 0);

        // As we know in Tabulation, we have to convert the Recursive Memoization code to an iterative code.

        // So, first we need to convert the base case.

        // If you observe carefull, you can easily fill the 0th row of dp array, where 0th row represents day 0. So when you are at the day 0 it is 100% sure that you reached day 0 from day 1 and you must have performed some task/activity on day 1, so you cannot perform that same activity again on day 0 (Reason: we cannot perform same activity on consecutive days).

        // So, if you performed task 0 on day 1, it means you cannot perform task 0 on day 0, it means except for task 0, we can perform task 1 or task 2 and our answer is the max(points[task 1], points[task 2]).
        // So, dp[0] = max(points[task 1], points[task 2]).
        dp[0] = max(points[0][1], points[0][2]);

        // So, if you performed task 1 on day 1, it means you cannot perform task 1 on day 0, it means except for task 1, we can perform task 0 or task 2 and our answer is the max(points[task 0], points[task 2]).
        // So, dp[1] = max(points[task 0], points[task 2]).
        dp[1] = max(points[0][0], points[0][2]);

        // So, if you performed task 2 on day 1, it means you cannot perform task 2 on day 0, it means except for task 2, we can perform task 0 or task 1 and our answer is the max(points[task 0], points[task 1]).
        // So, dp[2] = max(points[task 0], points[task 1]).
        dp[2] = max(points[0][0], points[0][1]);

        // dp[3], where 3 means no task is perfromed yet. So, dp[0][3] = max(points[task 0], points[task 1], points[task 2]).
        dp[3] = max(points[0][0], max(points[0][1], points[0][2]));

        for (int day = 1; day < n; day++)
        {
            vector<int> temp(4, 0);

            for (int lastActivityPerformed = 0; lastActivityPerformed < 4; lastActivityPerformed++)
            {
                for (int activity = 0; activity <= 2; activity++)
                {
                    // We cannot perform same activity on consecutive days.
                    if (activity != lastActivityPerformed)
                    {
                        int currPoints = points[day][activity] + dp[activity];
                        temp[lastActivityPerformed] = max(temp[lastActivityPerformed], currPoints);
                    }
                }
            }

            dp = temp;
        }

        return dp[3];
    }

public:
    /* Question: A Ninja has an ‘N’ Day training schedule. He has to perform one of these three activities (Running, Fighting Practice, or Learning New Moves) each day. There are merit points associated with performing an activity each day. The same activity can’t be performed on two consecutive days. We need to find the maximum merit points the ninja can attain in N Days.

    We are given a 2D Array POINTS of size ‘N*3’ which tells us the merit point of specific activity on that particular day. Our task is to calculate the maximum number of merit points that the ninja can earn. */
    int ninjaTraining(int n, vector<vector<int>> &points)
    {
        // // Recursive Solution.
        // return solveRecursive(n - 1, 3 /* Task numbers are from 0 to 2, so 3 means No Task Performed. */, points);

        // // DP Memoization Solution.
        // vector<vector<int>> dp(n, vector<int>(4, -1));
        // return solveMemoized(n - 1, 3, points, dp);

        // // DP Tabulation Solution.
        // return solveTabulized(n, points);

        // Space Optimized SOlution.
        return solveSpaceOptimized(n, points);
    }
};

int main(void)
{
    vector<vector<int>> points = {{10, 40, 70},
                                  {20, 50, 80},
                                  {30, 60, 90}};

    int n = points.size();

    // Solution.
    Solution S;
    cout << "Maximum Points : " << S.ninjaTraining(n, points) << ".\n";

    return 0;
}