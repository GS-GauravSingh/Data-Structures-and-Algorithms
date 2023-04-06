/*
Question :- give an array of integers, representing the height of rectangles, where width of each rectangle is 1. Your task is to return the area of largest rectangle.

----------------------------- Brute Force approach -----------------------
solution:- Area = length * breadth.
So, in order to return the area of largest rectangle we have to maximize the breadth.
In order to maximize the breadth, iterate to the left and right from the current element and check if we can extend the width of current element.

We can only extend the width if all the elements present at left or right is greater than or equal to the current element.

Ex:- heights = {2,1,5,6,2,3};
Solution:- we know that width of each rectangle is 1.

for 2:- there is no elements present at left, so we cannot extend the width of 2 in left side and we cannot extend the width of 2 in right size because the element present at right is 1 which is smaller than 2. So, area of 2 = height * width. area of 2 = 2 * 1 = 2.

Area of 2 = 2;

for 1:- we can extend the width of current element i.e., 1 in left side because element present at right is greater that 1. So, now width becomes 2 [width of 2 is 1, 1+1 = 2]. Nodw from left our width is 1.

in case of right we can extend the width of 1 till we reach to last element 3 because all the elements are greater than 1.
Now width from right becomes 4.

Area for 1 = height of 1 * width of 1;
Area = 1 * 5 + 1; [width = width from left + width from right .i.,e 4+1 = 5, +1 is for adding the width for current element].

Area of 1 = 6;

and that's how you can calculate the area of largest rectangle.

// Time complexity:- O(n^2)
// Space complexity:- O(1)

-------------------------- Optimized Approach ---------------------------------

Optimized Approach :- using stack.

for each element store the indexes of next smaller element and previous smaller element.

width = n * p - 1; , n = index of next smaller element, p = index of prev smaller element.
and length is constant, now you can easily find area.

// Time complexity:- O(n)
// Space complexity:- O(n)

*/
#include <bits/stdc++.h>
using namespace std;

/* ----------------------- Soluion Class ----------------------- */
class Solution
{
public:
    /* Brute Force Approach :- Using nested loops. */
    // Time Complexity :- O(n^2)
    // Space Complexity :- O(1)
    int largestRectangleArea_BruteForce(vector<int> &heights)
    {
        // Base case
        if (heights.size() == 1)
        {
            return heights[0];
        }

        // variable to store maximum area.
        int maxArea = INT_MIN;

        // traversing through the vector.
        for (int i = 0; i < heights.size(); i++)
        {
            // current bar height.
            int currentBarHeight = heights[i];

            // calculating the width.
            // width == 1, beacuse we are including the width of current bar.
            int width = 1;

            // In order to return the area of largest rectangle we have to maximize the breadth.
            // We can only extend the width, if all the elements present at left or right is greater than or equal to the current element.
            // Checking if we can extend the area of current bar to the left side.
            int extend = i - 1;
            while (extend >= 0 && heights[extend] >= currentBarHeight)
            {
                width++;
                extend--;
            }

            // Checking if we can extend the area of current bar to the right side.
            extend = i + 1;
            while (extend < heights.size() && heights[extend] >= currentBarHeight)
            {
                width++;
                extend++;
            }

            // calculating area.
            int area = currentBarHeight * width;

            // storing the maximum area.
            maxArea = max(area, maxArea);
        }

        return maxArea;
    }

    /*
    Optimized Approach :- Using stack.

    Intution :- For each element, we can store the indexes of next smaller element and previous smaller element because we can only extend the area of current bar towards left and right until, we found a bar having height less than the height of current bar.

    We cannot extend the area when we found a bar having height less than the height of current bar.

    width = n - p - 1, n = index of next smaller element, p = index of prev smaller element.

    Length is constant, now you can easily find area.
    */

    /* Next Smaller Element. */
    // Time Complexity :- O(n), n is the size of vector.
    // Space Complexity :- O(n),because we are using stack data structure.
    vector<int> nextSmallerElement(vector<int> &arr, int n)
    {
        // vector to store answer.
        vector<int> ans(n, 0);

        // stack.
        stack<int> st;
        // pushing -1 into stack, because we are going to traverse the vector from right,
        // and we know that, for the right most element the next smaller element is -1.
        st.push(-1);

        // traverse through the vector from back side.
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() != -1 && arr[st.top()] >= arr[i])
            {
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }

    /* Previous Smaller Element. */
    // Time Complexity :- O(n), n is the size of vector.
    // Space Complexity :- O(n),because we are using stack data structure.
    vector<int> previousSmallerElement(vector<int> &arr, int n)
    {
        // vector to store answer.
        vector<int> ans(n, 0);

        // stack.
        stack<int> st;
        // pushing -1 into stack, because we are going to traverse the vector from left,
        // and we know that, for the left most element the previous smaller element is -1.
        st.push(-1);

        // traverse through the vector.
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && st.top() != -1 && arr[st.top()] >= arr[i])
            {
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }

    // Time Complexity :- O(n), n is the size of vector.
    // Space Complexity :- O(n), because we are using stack data structure.
    int largestRectangleArea_Optimized(vector<int> &heights)
    {
        // Base case
        if (heights.size() == 1)
        {
            return heights[0];
        }

        // variable to store maximum area.
        int maxArea = INT_MIN;

        // for each element store the indexs of previous and next smaller element.
        vector<int> nextSmaller(heights.size(), 0);
        nextSmaller = nextSmallerElement(heights, heights.size());

        printVec(nextSmaller);

        vector<int> previousSmaller(heights.size());
        previousSmaller = previousSmallerElement(heights, heights.size());
        printVec(previousSmaller);

        for (int i = 0; i < heights.size(); i++)
        {
            // Corner Cases.
            // If there is no next smaller element for current bar, it means we can extend area of this bar till end (in right side).
            if (nextSmaller[i] == -1)
            {
                nextSmaller[i] = heights.size();
            }

            // If there is no previous smaller element for current bar, it means we can extend area of this bar till start of the vector.
            // if (previousSmaller[i] == -1)
            // {
            //     previousSmaller[i] = 0;
            // }

            // computing area.
            int length = heights[i];
            int breadth = nextSmaller[i] - previousSmaller[i] - 1;
            int area = length * breadth;

            // storing maximum area.
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }

    /* Method to print Vector. */
    void printVec(vector<int> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(void)
{
    vector<int> heights = {1, 1};

    // Solution.
    Solution S;
    // cout << S.largestRectangleArea_BruteForce(heights);
    cout << S.largestRectangleArea_Optimized(heights);
}