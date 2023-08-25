#include <bits/stdc++.h>
using namespace std;

class Solution
{

    /* Helper Method, The purpose of this function is to check if it's possible to eat all bananas within 'h' hours with a given eating speed k */

    // Time Complexity: O(n), where 'n' is the size of the 'piles' vector.
    // Space Complexity: O(1).
    bool canFinishOrNot(vector<int> &piles, int h, int k)
    {
        long long int hours = 0; // use long long to avoid Integer Overflow.
        for (int bananas : piles)
        {
            // If Koko has 'n' bananas to finish and she can finish 'k' bananas per hour. So, Koko will take a total of 'n/k' hours to finish all the bananas.
            // Example: If Koko has 'n = 10' bananas to finish and she can finish 'k = 2' bananas per hour. So, Koko will take a total of 'n/k = 10/2 = 5' hours to finish all the bananas.

            // Example: If Koko has 'n = 11' bananas to finish and she can finish 'k = 2' bananas per hour. So, Koko will take a total of 'n/k = 11/2 = 5' hours to finish all the bananas, but 1 banana still left and KoKo cannot move to the next pile before finishing up all the bananas in the current pile after she finishes all the bananas in the current pile then she can move to the next pile of bananas.

            // So, KoKo wwill take total 6 hours to finish all bananas.

            hours += bananas / k;

            // So, if total number of bananas is divisible by 'k', it means she can finish all bananas in total of 'n/k' hours, but if total number of bananas is not divisible by 'k', the she can finish all the bananas in 'n/k + 1' hours.
            if (bananas % k)
            {
                hours++;
            }
        }

        // If hours <= h, it means KoKo finishes all the piles of banans within 'h' hours. So, return true, Otherwise return false.
        if (hours <= h)
        {
            return true;
        }

        return false;
    }

public:
    // Time Complexity: O(n) for finding maximum element of array + O(n * log(n)) for finding answer.
    // Space Complexity: O(1).
    int minEatingSpeed(vector<int> &piles, int h)
    {

        // Size of vector.
        int n = piles.size();

        /*
        So, our search space is from 0 to maximum element of array.
        Why Search space [1, max_element(piles)] ?

        Because the minimum number of bananas KoKo can eat per hour is 1, which means that eating speed KoKo cannot be lower than 1 and the maximum number of bananas KoKo can eat is max_element(piles). Suppose, the maximum element of arrays is 35 and the size of the arrays is 5. So, if Koko eats 35 bananas per hour, then she finishes all the bananas in 5 hours.

        And our task is to return minimum no. of bananas KoKo can eat so that she can finish all the piles of bananas within h hours.
        */
        int low = 1;
        int high = INT_MIN;
        for (int i : piles)
        {
            high = max(high, i);
        }

        // variable to store answer.
        int ans = 0;

        // Binary Search.
        while (low <= high)
        {
            // Mid.
            int mid = low + (high - low) / 2;

            // Now we have to check, if Koko eats 'mid' number of bananas per hour, then she can finish all the piles of bananas within 'h' hour or not.
            if (canFinishOrNot(piles, h, mid))
            {
                // If she finishes all the piles of bananas eating 'mid' number of bananas per hour, then it is obvious that she finishes all the piles of bananas eating more that 'mid'  number of bananas per hour.
                // So, store this speed of koko and move to left half to find the best possible answer.
                ans = mid;

                high = mid - 1;
            }

            else
            {
                // It means, if Koko eats 'mid' number of bananas per hour, then she did not finish all the piles of bananas within 'h' hours.
                // Move to right half.
                low = mid + 1;
            }
        }

        return ans;
    }
};

int main(void)
{
    vector<int> piles{30, 11, 23, 4, 20};
    int h = 5;

    // Solution.
    Solution obj;
    cout << "Koko should eat atleast " << obj.minEatingSpeed(piles, h) << " bananas/hr to finish all piles of bananas within " << h << " hours.";

    return 0;
}