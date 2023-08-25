#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /* Optimal Approach: Using unordered_map.

    Time Complexity: O(n) + O(m), where 'n' and 'm' are the sizes of both the vectors.
    Space Complexity: O(nums1.size()), space used by unordered_map.
    */
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {

        // Delrae an unordered_map.
        unordered_map<int, int> map;

        // vector to store answer.
        vector<int> ans;

        // Iterate through the element of any one of the given vectors and store the frequence of element into our map.
        for (auto it : nums1)
        {
            map[it]++;
        }

        // Now, traverse that vector whose element are not inserted into the map.
        for (int i = 0; i < nums2.size(); i++)
        {
            // Now, check whether this current element of nums2 is present in the map or not, if it is present, it means this element is common in both the vector.
            // So, store this element into our answer vector and decrement its frequency.
            // if the frequence of this element is 0, it means, nums2 contains more occurences of this element as compare to nums1, so we cannot store this element.
            if (map.find(nums2[i]) != map.end())
            {
                // we only store this common element, if it is having frequency > 0.
                if (map[nums2[i]] > 0)
                {
                    ans.push_back(nums2[i]);
                }

                // decrement the frequence.
                map[nums2[i]]--;
            }
        }

        // finally return answer.
        return ans;
    }
};

int main(void)
{
    vector<int> nums1{1, 2, 2, 1}, nums2{2, 2};

    // Solution.
    Solution obj;
    vector<int> intersection = obj.intersect(nums1, nums2);

    for (auto i : intersection)
    {
        cout << i << " ";
    }
    return 0;
}