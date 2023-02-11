/*
Question :-
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max trappedWater of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1


Constraints:
n == height.length
2 <= n <= 10^5
0 <= height[i] <= 10^4
*/
public class ContainerWithMostWater {
    /* Approach 1 :- Using nested loops. */
    // Time Complexity :- O(n^2)
    // Space Complexity :- O(1)
    static int maxArea_Approach_1(int heights[]) {

        // size of array.
        int n = heights.length;

        // variable to store answer.
        int maxWaterTrapped = 0;

        // iterate through the array and find answer.
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                // calculation.
                int height = Math.min(heights[i], heights[j]);
                int width = j - i;
                int trappedWater = height * width;

                System.out.println("Area (" + heights[i] + "," + heights[j] + ") = " + trappedWater);

                // store maximum trapped water.
                maxWaterTrapped = Math.max(maxWaterTrapped, trappedWater);
            }
            System.out.println();
        }

        return maxWaterTrapped;
    }

    /* Approach 2 :- Using 2 pointer's. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(1)
    static int maxArea_Approach_2(int heights[]) {

        // size of array.
        int n = heights.length;

        // variable to store answer.
        int maxWaterTrapped = 0;

        // 2 pointer
        int left = 0;
        int right = n - 1;

        while (left < right) {
            // left tower height.
            int leftHeight = heights[left];

            // right tower height.
            int rightHeight = heights[right];

            // height
            int height = Math.min(leftHeight, rightHeight);

            // width
            int width = right - left;

            // area
            int trappedWater = height * width;

            // maximum wate trapped.
            maxWaterTrapped = Math.max(maxWaterTrapped, trappedWater);

            // move pointers.
            if (leftHeight < rightHeight) {
                left++;
            } else {
                right--;
            }
        }

        return maxWaterTrapped;
    }

    public static void main(String[] args) {
        int[] heights = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
        System.out.println(maxArea_Approach_1(heights));
        System.out.println(maxArea_Approach_2(heights));

    }
}
