#include <bits/stdc++.h>
using namespace std;

class Solution
{
    /* Method to Merge two sorted arrays. */
    // Time Complexity: O(nums1.size() + nums2.size()).
    // Space Complexity: O(nums1.size() + nums2.size()), space used to store all the elements in sorted order.
    vector<int> mergeSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        // Size of the vectors.
        int nums1_size = nums1.size();
        int nums2_size = nums2.size();

        // vector to store the result of merging.
        vector<int> mergedArray;

        // Pointers to traverse nums1 and nums2 vector.
        int i = 0, j = 0;

        // Merge.
        while (i < nums1_size && j < nums2_size)
        {
            if (nums1[i] <= nums2[j])
            {
                mergedArray.push_back(nums1[i++]);
            }
            else
            {
                // nums1[i] > nums2[j].
                mergedArray.push_back(nums2[j++]);
            }
        }

        // Process Remaining elements of nums1 array.
        while (i < nums1_size)
        {
            mergedArray.push_back(nums1[i++]);
        }

        // Process Remaining elements of nums2 array.
        while (j < nums2_size)
        {
            mergedArray.push_back(nums2[j++]);
        }

        // Reture the result.
        return mergedArray;
    }

    /* Brute Force Approach: Merge all the 'R' rows into a single vector and then find the median. */
    // Time Complexity: O(R*(C+C)), in total we have 'R' rows and 'C+C' time to merge 2 rows.
    // Space Complexity: O(R*C), space used by auxiliary vector.
    int median_BruteForce(vector<vector<int>> &matrix, int R, int C)
    {
        // Merging all rows.
        vector<int> merge = mergeSortedArrays(matrix[0], matrix[1]);
        for (int i = 2; i < R; i++)
        {
            merge = mergeSortedArrays(merge, matrix[i]);
        }

        // Now, find the median.
        // See, the total number of Rows 'R' and total number columns 'C' are always Odd.
        // So, total elements in matrix = R * C. So, there are odd number of elements in the matrix.
        // Ex: R = 3, C = 3, totalElements = R*C = 3*3 = 9.
        // and in case of odd number of elements: Median = (n/2)th element, where 'n' is eauls to total number of elements.
        int totalElements = R * C;
        return merge[totalElements / 2];
    }

    /* Optimized Approach: Using Binary Search.

    Intution: Since, the value of 'R' and 'C' are always Odd, it means the total elements in the matrix is always odd and in case of odd number of elements our Median is = (n/2)th element,
    and if you carefull observe, if (n/2)th element is our median, then there sholud be exactly (n/2) elements that are smaller than the median element. Now, we can apply binary search and if we found any element that has (n/2) elements smaller then this elements is our median element.
    */

    /* Method to count the elements that are smaller than given target. */
    // Time COmplexity: O(R*log(C)).
    // Space Complexity: O(1).
    int countElementsSmallerThanTarget(vector<vector<int>> &matrix, int R, int C, int target)
    {
        // Now, you can traverse the entire matrix and count the elements that are smaller then target and this will cost you TC: O(R*C).

        // Since the array is row-wise sorted, we can apply binary search on each row to count the elements that are smaller then target and the time complexity of this is O(R*log(C)).

        // variable to store count of elements that are smaller then target.
        int smallerCnt = 0;

        // Traverse each row and apply binary search.
        for (int i = 0; i < R; i++)
        {
            // Needed variables for Binary Search.
            int low = 0;
            int high = C - 1;

            // Binary Search.
            while (low <= high)
            {
                // Mid.
                int mid = low + (high - low) / 2;

                if (matrix[i][mid] <= target)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }

            smallerCnt += low;
        }

        return smallerCnt;
    }

    // Time Complexity: O(), in total we have 'R' rows and 'C+C' time to merge 2 rows.
    // Space Complexity: O(1).
    int median_Optimized(vector<vector<int>> &matrix, int R, int C)
    {
        // Total Elements in matrix = R*C, where 'R' and 'C' are always Odd, it means the total elements in the matrix is always odd.
        int totalElements = R * C;

        // Pointers.
        // See, elements in the matrix are in the range of [1, 2000]. So, we can apply binary search in this search space.
        int low = 1;
        int high = 2000;

        // variable to store median element.
        int median = 0;

        // Binary Search.
        while (low <= high)
        {
            // Mid (Target Element).
            int mid = low + (high - low) / 2;

            // Target Element.
            int targetElement = mid;

            // Now, if (n/2) elements are smaller then this target 'mid', it means this is our median element.
            int smallerElementCount = countElementsSmallerThanTarget(matrix, R, C, targetElement);
            if (smallerElementCount <= (totalElements / 2))
            {
                low = mid + 1;
            }
            else
            {
                median = targetElement;
                high = mid - 1;
            }
        }

        return median;
    }

public:
    /* Question: Given a row wise sorted matrix of size R*C where R and C are always odd, find the median of the matrix. */
    int median(vector<vector<int>> &matrix, int R, int C)
    {

        // // Brute Force Approach.
        // return median_BruteForce(matrix, R, C);

        // Optimized Approach.
        return median_Optimized(matrix, R, C);
    }
};

int main(void)
{
    vector<vector<int>> matrix{
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}};
    int R = matrix.size();
    int C = matrix[0].size();

    // Solution.
    Solution obj;
    cout << "Median Element: " << obj.median(matrix, R, C) << ".";
    return 0;
}