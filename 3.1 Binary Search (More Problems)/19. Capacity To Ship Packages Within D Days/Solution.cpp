#include <bits/stdc++.h>
using namespace std;

class Solution
{

    /* This function checks whether it's possible to ship all the packages within 'd' days with the ship weight capacity of 'shipCapacity'. */
    // Time Complexity: O(n), where 'n' is the size of the weights vector.
    // Space Complexity: O(1).
    bool isPossibleToShip(vector<int> &weights, int d, int shipCapacity)
    {
        int packagesWeight = 0;
        int days = 1;
        for (int i = 0; i < weights.size(); i++)
        {
            if (packagesWeight + weights[i] <= shipCapacity)
            {
                packagesWeight += weights[i];
            }
            else
            {
                days++;
                packagesWeight = weights[i];
            }
        }

        // return true if the total days are less than or equal to d, indicating successful shipment, otherwise false.
        if (days <= d)
        {
            return true;
        }

        return false;
    }

public:
    // Time Complexity: O(n) for calculating sum and finding maximum element of array + O(n* log(n)) for finding answer, where 'n' is the size of the weights vector.
    // Space Complexity: O(1).
    int shipWithinDays(vector<int> &weights, int d)
    {

        // To ship all the packages, the ship must have a minimum capacity equal to or greater than the weight of the maximum element in the array of package weights. This ensures that the ship can handle the heaviest package.

        // Example: weights: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], the ship must have a minimum capacity of 10kg. If the capacity is less than 10kg, it would be impossible to ship a package with a weight of 10kg, resulting in incomplete shipping and our task is to ship all the packages.

        // So, Minimum Capacity of Ship = Maximum element of array.

        // The maximum capacity of the ship required to ship all packages is equal to the sum of the weights of all the packages because in this way the ship were able to store all the packages and all the packages will be shipped within a single day.

        // Maximum Capacity = Sum of the weights of all the packages.
        int low = INT_MIN;
        int high = 0;
        for (int i : weights)
        {
            low = max(low, i);
            high += i;
        }

        // variable to store least weight capacity of ship.
        int ans = 0;

        // Binary Search.
        while (low <= high)
        {
            // Mid
            int mid = low + (high - low) / 2;

            // Now, we just have to check, whether this capacity 'mid' is enough to ship all the packages within 'd' days or not.
            if (isPossibleToShip(weights, d, mid))
            {
                // If it is possible to ship all the packages within 'd' days and with the weight capacity of 'mid'.
                // So, the weight capacity 'mid' can be your possible answer.
                // Now, If it is possible to ship all the packages within 'd' days and with the weight capacity of 'mid'. Now, if you take the weight capacity of ship more than 'mid', then it is also possible to ship all the packages.
                // And our task is to find the least capacity of ship.
                // So, move to left half.
                ans = mid;
                high = mid - 1;
            }

            // Now, If it is not possible to ship all the packages within 'd' days and with the weight capacity of 'mid'. It means we have to increase the weight capacity. So, move to right half.
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};

int main(void)
{
    vector<int> weights{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int d = 5;

    // SOlution.
    Solution obj;
    cout << "Least weight capacity of ship is: " << obj.shipWithinDays(weights, d) << ".";
    return 0;
}