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

    /* Method to find the median element. */
    // Time Complexity: O(1).
    // Space Complexity: O(1).
    double findMedian(vector<int> &mergedArray)
    {
        /*
        Question: What is Median?
        Answer:   Median, in statistics, is the middle value of the given list of data when arranged in an order. The arrangement of data or observations can be made either in ascending order or descending order.

        When the dataset has an odd number of elements, the median is simply the middle value.
        Formula: Median = n/2th element.
        For example, in the dataset {2, 4, 6, 8, 10}, the median is 6.

        When the dataset has an even number of elements, the median is the average/mean of the two middle values.
        Formula: Median = ( (n/2)th element + (()n/2)-1)th element) / 2.
        For example, in the dataset {2, 4, 6, 8}, the median is (4 + 6) / 2 = 5.
        */

        // Size of the merged vector.
        int n = mergedArray.size();

        // If mergedArray has an odd number of elements, the median is simply the middle value.
        if (n & 1)
        {
            // Formula: Median = n/2th element.
            double median = mergedArray[(n / 2)];
            return median;
        }

        // else, mergedArray has an even number of elements the median is the average/mean of the two middle values.
        // Formula: Median = ( (n/2)th element + (()n/2)-1)th element) / 2.
        double median = (mergedArray[(n / 2)] + mergedArray[((n / 2) - 1)]) / 2.0;
        return median;
    }

    /* Brute Force Approach: Using Auxiliary array.
    Intution: Both the arrays are sorted in increasing order, so what we can do is, merge both the sorted arrays into a single array and then find the median element. */

    // Time Complexity: O(nums1.size() + nums2.size()) is for merging both the arrays.
    // Space Complexity: O(nums1.size() + nums2.size()), space used to store all the elements in sorted order.
    double findMedian_BruteForce(vector<int> &nums1, vector<int> &nums2)
    {
        // Step 1: Merge both the sorted arrays.
        vector<int> mergedArray = mergeSortedArrays(nums1, nums2);

        // Step 2: Find median element.
        /*
        Question: What is Median?
        Answer:   Median, in statistics, is the middle value of the given list of data when arranged in an order. The arrangement of data or observations can be made either in ascending order or descending order.

        When the dataset has an odd number of elements, the median is simply the middle value.
        For example, in the dataset {2, 4, 6, 8, 10}, the median is 6.

        When the dataset has an even number of elements, the median is the average/mean of the two middle values.
        For example, in the dataset {2, 4, 6, 8}, the median is (4 + 6) / 2 = 5.
        */
        double median = findMedian(mergedArray);

        // Step 3: Return Median.
        return median;
    }

    /* Better Approach: Using Two-Pointers.
    Intution: Since both the arrays are sorted in increasing order, we can use two-pointers to find the median element or elements. In the above approach we are merging both the vector and storing the result into a separate vector and this will increase our SC, instead of storing the result the entire result, we can store our median element into variables.
    */
    // Time Complexity: O(nums1.size() + nums2.size()).
    // Space Complexity: O(1).
    double findMedian_Better(vector<int> &nums1, vector<int> &nums2)
    {
        // Size of the vectors.
        int nums1_size = nums1.size();
        int nums2_size = nums2.size();

        // Total elements.
        int size = nums1_size + nums2_size;

        // Odd number of elements, the median is simply the middle value.
        if (size & 1)
        {
            // variable to store median element.
            double medianElement = -1;

            // Median element index.
            int medianIdx = (size / 2);

            // Pointers to traverse nums1 and nums2 vector.
            int i = 0, j = 0;

            // Merge.
            while (i < nums1_size && j < nums2_size && medianIdx >= 0)
            {
                if (nums1[i] <= nums2[j])
                {
                    if (medianIdx == 0)
                    {
                        medianElement = nums1[i];
                    }

                    i++;
                }
                else
                {
                    // nums1[i] > nums2[j].

                    if (medianIdx == 0)
                    {
                        medianElement = nums2[j];
                    }

                    j++;
                }

                medianIdx--;
            }

            // Process Remaining elements of nums1 array.
            while (i < nums1_size && medianIdx >= 0)
            {
                if (medianIdx == 0)
                {
                    medianElement = nums1[i];
                }
                medianIdx--;

                i++;
            }

            // Process Remaining elements of nums2 array.
            while (j < nums2_size && medianIdx >= 0)
            {
                if (medianIdx == 0)
                {
                    medianElement = nums2[j];
                }
                medianIdx--;

                j++;
            }

            return medianElement;
        }

        // else, we have even number of elements then, the median is the average/mean of the two middle values.
        // variable to store two middle elements.
        int midValue_1 = -1, midValue_2 = -1;

        // Median elements index.
        int medianIdx_1 = size / 2, medianIdx_2 = (size / 2) - 1;

        // Pointers to traverse nums1 and nums2 vector.
        int i = 0, j = 0;

        // Merge.
        while (i < nums1_size && j < nums2_size)
        {
            if (nums1[i] <= nums2[j])
            {
                if (medianIdx_1 == 0)
                {
                    midValue_1 = nums1[i];
                }
                else if (medianIdx_2 == 0)
                {
                    midValue_2 = nums1[i];
                }

                i++;
            }
            else
            {
                // nums1[i] > nums2[j].

                if (medianIdx_1 == 0)
                {
                    midValue_1 = nums2[j];
                }
                else if (medianIdx_2 == 0)
                {
                    midValue_2 = nums2[j];
                }

                j++;
            }

            medianIdx_1--;
            medianIdx_2--;
        }

        // Process Remaining elements of nums1 array.
        while (i < nums1_size)
        {
            if (medianIdx_1 == 0)
            {
                midValue_1 = nums1[i];
            }
            else if (medianIdx_2 == 0)
            {
                midValue_2 = nums1[i];
            }
            medianIdx_1--;
            medianIdx_2--;

            i++;
        }

        // Process Remaining elements of nums2 array.
        while (j < nums2_size)
        {
            if (medianIdx_1 == 0)
            {
                midValue_1 = nums2[j];
            }
            else if (medianIdx_2 == 0)
            {
                midValue_2 = nums2[j];
            }
            medianIdx_1--;
            medianIdx_2--;

            j++;
        }

        double medianElement = (midValue_1 + midValue_2) / 2.0;
        return medianElement;
    }

    /* Optimized Approach 2: Using Binary Search. */
    double findMedian_Optimized(vector<int> &nums1, vector<int> &nums2)
    {
        // Apply Binary Seacrh on smaller size array.
        if (nums1.size() > nums2.size())
        {
            return findMedian_Optimized(nums2, nums1);
        }

        // Size of the vectors.
        int nums1_size = nums1.size();
        int nums2_size = nums2.size();

        // Total elements.
        int total_elements = nums1_size + nums2_size;

        // Pointers.
        int low = 0, high = nums1_size;

        // Binary Search.
        while (low <= high)
        {
            // Cut 1 index.
            int cut_1 = low + (high - low) / 2;

            // Cut 2 index.
            int cut_2 = (total_elements / 2) - cut_1;

            // left1, left2, right1, right2.
            int left_1 = ((cut_1 == 0) ? INT_MIN : nums1[cut_1 - 1]);
            int left_2 = ((cut_2 == 0) ? INT_MIN : nums2[cut_2 - 1]);

            int right_1 = ((cut_1 == nums1_size) ? INT_MAX : nums1[cut_1]);
            int right_2 = ((cut_2 == nums2_size) ? INT_MAX : nums2[cut_2]);

            // Condition for valid partition.
            if (left_1 <= right_2 && left_2 <= right_1)
            {
                // Odd Number of elements.
                if (total_elements & 1)
                {
                    return min(right_1, right_2);
                }

                // Even number of elements.
                else
                {
                    return ((max(left_1, left_2) + min(right_1, right_2)) / 2.0);
                }
            }

            else if (left_1 > right_2)
            {
                high = cut_1 - 1;
            }
            else
            {
                // left_2 > right_1.
                low = cut_1 + 1;
            }
        }

        // to avoid error.
        return 0.0;
    }

public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {

        // // Brute Force Approach.
        // return findMedian_BruteForce(nums1, nums2);

        // // Better Approach 1 (Space Optimized Approach).
        // return findMedian_Better(nums1, nums2);

        // Optimized.
        return findMedian_Optimized(nums1, nums2);
    }
};

int main(void)
{
    vector<int> nums1{1, 2}, nums2{3, 4};

    // Solution.
    Solution obj;
    cout << "Median = " << fixed << setprecision(5) << obj.findMedianSortedArrays(nums1, nums2) << ".";

    return 0;
}