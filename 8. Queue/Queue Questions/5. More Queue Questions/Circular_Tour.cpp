/*

Question:-

Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
1. The amount of petrol that every petrol pump has.
2. Distance from that petrol pump to the next petrol pump.
Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.

Approach 1:- Brute Force.

We have to start from each station and for each station we need to check if we have enough petrol to go to the next station (remainingPetrol = petrol at this station - distance to next station).
if remainingPetrol < 0, it means, from this station we cannot go to the next station, in that case break and start from next station.

if remainingPetrol > 0, it means, from this station we can go to the next station, in that case keep checking untill you reach the starting point.

Time Complexity:- O(n^2)
Space Complexity:- O(1)


Approach 2:- Optimized.

Property 1:- Calculate total petrol and total distance you need to cover.
if(total petrol < total distance){
    // you can travel 1 unit distance in 1 litre of petrol, and in this case total petrol < total distance, it means there is no successfull route exists.
}

Property 2:- if total petrol >= total distance you need to cover, in that case setup two pointer i and j.

suppose in a circle there are 5 petrol pumps, if we start from 1st petrol pump,
path(1 -> 2 -> 3) is successfull, but
path(3 -> 4), fails, we cannot go from 3rd petrol pump to 4th petrol pump, in that case we start from 5th petrol pump.

With the brute force idea, if #1 doesn't work out we have to start with #2 to check and so on.
Is it necessary? No. We don't have to check from #2 because we've known that it won't pass #4.

With this property, we further conclude that, once we find a failed path(#i -> #j), we can set up the starting point from the next point #j+1. In the code, start = i+1.

Property 3:- if we find a starting point X that can reach the last station, we don't have to loop back to check stations before X. The petrol will always be enough to cover the rest trip.

Time Complexity:- O(n)
Space Complexity:- O(1)

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

class Solution
{
public:
    // Function to find starting point where the truck can start to get through
    // the complete circle without exhausting its petrol in between.

    /* ------------------- Brute Force Code ------------------------------------

        Time Complexity:- O(n^2)
        Space Complexity:- O(1)

    */
    int tour(petrolPump p[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            int remainingPetrol = 0;
            bool isSuccess = true;

            for (int j = i; j < n + i; j++)
            {
                int station = j % n; // j%n is used to maintain circular manner.
                remainingPetrol += p[station].petrol - p[station].distance;

                if (remainingPetrol < 0)
                {
                    // if remainingPetrol < 0, it means, from this station we cannot go to the next station, in that case break and start from next station.
                    isSuccess = false;
                    break;
                }
            }

            if (isSuccess == true)
            {
                // if isSuccess == true, it means we got the starting point, from where we can complete the cirle, return the index of stating point.
                return i;
            }
        }

        // return -1, means there is no starting point from where we can complete the circle.
        return -1;
    }

    /* ------------------------------- Optimized Code ----------------------------

        Time Complexity:- O(n)
        Space Complexity:- O(1)

    */
    int tour_Optimized(petrolPump p[], int n)
    {
        int totalPetrol = 0;
        int totalDistance = 0;
        int remainingPetrol = 0;
        int start = 0;

        // Property 1: We compare total petrol and total distance.
        for (int i = 0; i < n; i++)
        {
            totalPetrol += p[i].petrol;
            totalDistance += p[i].distance;
        }

        // if total petrol < total distance, it means there is no successfull route exists.
        if (totalPetrol < totalDistance)
        {
            return -1;
        }

        // If total petrol >= total distance, we set up a pointer i starting from #1 and traverse.

        // Property 3: no need to check for stations before starting point.
        for (int i = 0; i < n; i++)
        {
            // for each station, we calculate the remaining petrol.
            remainingPetrol += p[i].petrol - p[i].distance;

            // If the remainPetrol < 0, that means it's impossible to go to next station - it will be an unsuccessful route.

            // Start from i+1, we know we start with empty tank, so remainintPetrol = 0;
            if (remainingPetrol < 0)
            {
                start = i + 1;
                remainingPetrol = 0;
            }
        }

        // return the index of starting point.
        return start;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        petrolPump p[n];
        for (int i = 0; i < n; i++)
            cin >> p[i].petrol >> p[i].distance;
        Solution obj;
        cout << obj.tour(p, n) << endl;
    }
}

// } Driver Code Ends