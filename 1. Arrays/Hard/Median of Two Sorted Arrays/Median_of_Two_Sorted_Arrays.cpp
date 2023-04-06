/*
Question :-
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).


Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.


Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.


Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-10^6 <= nums1[i], nums2[i] <= 10^6
*/

#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
    /* Additional function to print vector, TC:- O(n), SC:- O(1). */
    void printVec(vector<int> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    /* ---------------------------- Below Methods used in Approach 1 ------------------------------------  */

    /* Method to merge 2 sorted arrays of different size. TC:- O(m+n), SC:- O(m+n). */
    vector<int> merge2SortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> merged;

        int i = 0, j = 0;

        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] <= nums2[j])
            {
                merged.push_back(nums1[i++]);
            }
            else
            {
                merged.push_back(nums2[j++]);
            }
        }

        // remaining elements.
        while (i < nums1.size())
        {
            merged.push_back(nums1[i++]);
        }

        while (j < nums2.size())
        {
            merged.push_back(nums2[j++]);
        }

        return merged;
    }

    /* Function to find median element. TC:- O(1), SC:- O(1) */
    double find_median(vector<int> &arr)
    {

        double median = -1;
        int size = arr.size();

        if (size & 1)
        {
            // odd length
            median = arr[size / 2];
        }
        else
        {
            // even length
            median = (arr[size / 2] + arr[(size / 2) - 1]) / 2.0;
        }
        return median;
    }

    /* ---------------------------- Below Methods used in Approach 2 ------------------------------------  */
    double returnMedianElement(vector<int> &nums1, vector<int> &nums2)
    {
        // total elements.
        int totalElements = nums1.size() + nums2.size();

        // odd elements, median = (n/2)th element.
        if (totalElements & 1)
        {
            // index of median elements.
            int medianIdx = totalElements / 2;

            // find the median element.
            int count = -1;
            double medianElement = -1;
            int i = 0, j = 0;
            while (i < nums1.size() && j < nums2.size())
            {
                count++;
                if (nums1[i] <= nums2[j])
                {

                    if (count == medianIdx)
                    {
                        medianElement = (double)nums1[i];
                    }

                    i++;
                }
                else
                {

                    if (count == medianIdx)
                    {
                        medianElement = (double)nums2[j];
                    }

                    j++;
                }
            }

            // remaining elements
            while (i < nums1.size())
            {
                count++;

                if (count == medianIdx)
                {
                    medianElement = (double)nums1[i];
                }

                i++;
            }
            while (j < nums2.size())
            {

                count++;

                if (count == medianIdx)
                {
                    medianElement = (double)nums2[j];
                }

                j++;
            }

            return medianElement;
        }

        // even elements, median = (((n/2) - 1)th element + (n/2)th element) / 2.
        // index of median elements.
        int medianIdx_1 = totalElements / 2;
        int medianIdx_2 = totalElements / 2 - 1;

        // find the median element.
        int count_1 = -1;
        int count_2 = -1;
        double medianElement_1 = -1;
        double medianElement_2 = -1;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] <= nums2[j])
            {
                count_1++;
                count_2++;

                if (count_1 == medianIdx_1)
                {
                    medianElement_1 = (double)nums1[i];
                }
                else if (count_2 == medianIdx_2)
                {
                    medianElement_2 = (double)nums1[i];
                }

                i++;
            }
            else
            {
                count_1++;
                count_2++;

                if (count_1 == medianIdx_1)
                {
                    medianElement_1 = (double)nums2[j];
                }
                else if (count_2 == medianIdx_2)
                {
                    medianElement_2 = (double)nums2[j];
                }

                j++;
            }
        }

        // remaining elements.
        while (i < nums1.size())
        {

            count_1++;
            count_2++;

            if (count_1 == medianIdx_1)
            {
                medianElement_1 = (double)nums1[i];
            }
            else if (count_2 == medianIdx_2)
            {
                medianElement_2 = (double)nums1[i];
            }

            i++;
        }

        while (j < nums2.size())
        {
            count_1++;
            count_2++;

            if (count_1 == medianIdx_1)
            {
                medianElement_1 = (double)nums2[j];
            }
            else if (count_2 == medianIdx_2)
            {
                medianElement_2 = (double)nums2[j];
            }

            j++;
        }

        cout << medianElement_1 << " " << medianElement_2 << endl;
        cout << medianIdx_1 << " " << medianIdx_2 << endl;
        double median = (medianElement_1 + medianElement_2) / 2;

        return median;
    }

public:
    /* Approach 1 :- merge both sorted array and return the median.  */
    // Time Complexity :- O(m+n)
    // Space Complexity :- O(m+n)
    double findMedianSortedArrays_Approach_1(vector<int> &nums1, vector<int> &nums2)
    {
        // step 1:- merge 2 sorted arrays.
        vector<int> merge = merge2SortedArrays(nums1, nums2);
        printVec(merge);

        // step 2:- find median.
        double median = find_median(merge);

        // step 3:- return median.
        return median;
    }

    /* Approach 2 :- Optimizing approach 1.  */
    // Time Complexity :- O(m+n)
    // Space Complexity :- O(1)
    double findMedianSortedArrays_Approach_2(vector<int> &nums1, vector<int> &nums2)
    {
        double median = returnMedianElement(nums1, nums2);

        return median;
    }

    /* Approach 3 :- Using Binary Search.  */
    // Time Complexity :- O(log(m+n) )
    // Space Complexity :- O(1)
    double findMedianSortedArrays_Approach_3(vector<int> &nums1, vector<int> &nums2)
    {
        // If the size of both arrays are same ,then you can apply Binary Search on any one of the given array.
        // But, if the size of both arrays are different ,then always apply Binary Search on smaller size array.

        if (nums1.size() > nums2.size())
        {
            // when the length of both the arrys are different,
            // then apply binary search on shorted array to avoid index out of bound.

            findMedianSortedArrays_Approach_3(nums2, nums1);
        }

        // size of arrys.
        int n1 = nums1.size();
        int n2 = nums2.size();

        // variable for binary search
        int low = 0;
        int high = n1;

        while (low <= high)
        {
            // mid
            int mid = low + (high - low) / 2;

            // Initializing the cuts or partitons.
            int cut1 = mid;
            int cut2 = ((n1 + n2) / 2) - cut1;

            // initializing l1,l2,r1,r2.
            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];

            int r1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
            int r2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

            if (l1 > r2)
            {
                // shift elemnets to the left.
                high = cut1 - 1;
            }
            else if (l2 > r1)
            {
                // shift elements to the right.
                low = cut1 + 1;
            }
            else
            {

                // odd length
                if ((n1 + n2) & 1)
                {
                    double median = (double)min(r1, r2);
                    return median;
                }
                else
                {
                    // even length;
                    double leftHalfMax = max(l1, l2);
                    double rightHalfMin = min(r1, r2);

                    double median  = (leftHalfMax + rightHalfMin) /2.0;
                    return median;
                }
            }
        }
        return 0.0;
    }
};

int main()
{
    vector<int> nums1 = {2,3,4,5};
    vector<int> nums2 = {1};

    Solution S;
    // cout << S.findMedianSortedArrays_Approach_1(nums1, nums2) << endl;
    // cout << S.findMedianSortedArrays_Approach_2(nums1, nums2);
    cout << S.findMedianSortedArrays_Approach_3(nums1, nums2);
}