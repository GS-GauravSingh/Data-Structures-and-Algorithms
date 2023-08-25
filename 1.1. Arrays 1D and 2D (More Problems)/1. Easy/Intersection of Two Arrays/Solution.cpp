#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /* Optimal Approach: Using unordered_set.

    Time Complexity: O(n) + O(m), where 'n' and 'm' are the sizes of both vectors.
    Space Complexity: O(nums1.size()), space used by unordered_set.
    */
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        // Insert all the element of any one of the given vector into unordered_set.
        // Why unordered_set? because in question, it is cleary mentioned that Each element in the result must be unique.
        unordered_set<int> set;
        for (auto i : nums1)
        {
            set.insert(i);
        }

        // vector to store answer.
        vector<int> ans;

        // Now, traverse that vector whose element are not inserted into the set.
        for (int i = 0; i < nums2.size(); i++)
        {
            // Now, check whether this current element of nums2 is present in the set, if it is present, it means this element is common in both the vector.
            // So, store this element into our answer vector.
            if (set.find(nums2[i]) != set.end())
            {
                ans.push_back(nums2[i]);

                // after storing this element into our answer vector, erase this element from set, because we don't want any duplicates in our answer vector.
                set.erase(nums2[i]);
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
    vector<int> intersection = obj.intersection(nums1, nums2);

    for (auto i : intersection)
    {
        cout << i << " ";
    }
    return 0;
}