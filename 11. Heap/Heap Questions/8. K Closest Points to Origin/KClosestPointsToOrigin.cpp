#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
public:
    /* Approach : use the distance formula and calculate the distance of each coordinate with the origin and store the coordinate and its distance from origin in map and use Heap to find the K closest points.

    We know that the distance between the two points let it be (x1,y1) and (x2,y2) is written as
    sqrt( (x1−x2)^2 + (y1−y2)^2 ).

    In This case, we are calculating the distnace of coordinate with origin and coordinates of origin are (0,0).

    In This case,
    x1 = 0,
    y1 = 0,
    x2 = x,
    y2 = y.

    On putting these values in the above formula we get, sqrt( (0−x2)^2 + (0−y2)^2 ) = sqrt(x^2 + y^2).
    Hence the distance between the origin and the point P is sqrt(x^2 + y^2).

    So, the coordinate having minimum distance with the origin, that coordinate is closest to origin.
    */

    /* We have to find K coordinates that are closest to origin. */
    // Time Complexity: O(n*log(k))
    // Space Complexity: O(k), at any time our min heap does not contain more than k element.
    void KClosestPoints(vector<pair<int, int>> &coordinates, int k)
    {
        // Max Heap
        // First block of nested pair is used to store distance of coordinates with origin.
        // Second block of pair in nested pair is used to store the actual coordinates.
        priority_queue<pair<int, pair<int, int>>> pq;

        // traversing the array.
        for (int i = 0; i < coordinates.size(); i++)
        {
            // coordinates.
            int x = coordinates[i].first;
            int y = coordinates[i].second;

            // calculating the distance of coordinats (x, y) with origin suing the distance formula.
            // Formula = sqrt(x^2 + y^2).

            // the coordinate having minimum distance with the origin, that coordinate is closest to origin.
            // calculating and storing the distance.
            int temp = (x * x + y * y);
            int distance = sqrt(temp);

            // pushing the distance of coordinate with origin and actual coordinates into the max heap.
            // So that our max heap will sort the pairs according to the distance and the coordinates having maximum distance is present at the top of the max heap.
            pq.push({distance, {x, y}});

            // if the sie of Max Heap is > k, simply pop the top element.
            // becaue the top element is the coordinates having maximum distance with origin and these coordinates are not closest to origin.
            // because the coordinate that are closest to origin has minimum distance with origin.
            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        // After the above loop end, our Max Heap will contain the K coordinates that are closest to origin.
        while (!pq.empty())
        {
            // extracting the x, y coordinate.
            int x = pq.top().second.first;
            int y = pq.top().second.second;

            // printing the coordinate.
            cout << "[" << x << ", " << y << "] ";

            // popping the top element from the max heap.
            pq.pop();
        }
    }
};

int main(void)
{
    vector<pair<int, int>> coordinates = {
        {1, 3},
        {-2, 2},
        {5, 8},
        {0, 1},
    };

    int k = 2;

    // Solution.
    Solution S;
    S.KClosestPoints(coordinates, k);
}