#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Time Complexity: O(n), where 'n' is the size of the nums vector.
    // Space Complexity: O(1).
    vector<string> summaryRanges(vector<int> &nums)
    {

        // vector to store answer.
        vector<string> ans;

        // string to store range.
        string range = "";

        // Traverse the nume vector.
        for (int i = 0; i < nums.size(); i++)
        {
            // declare another pointer to traverse the array.
            int j = i;

            // Traverse the array till we don't find the breakpoint.
            while (j + 1 < nums.size() && nums[j + 1] == nums[j] + 1)
            {
                j++;
            }

            // Now, if j > i, it menas we got our range, [i, j].
            if (j > i)
            {
                range += to_string(nums[i]);
                range += "->";
                range += to_string(nums[j]);
            }

            // But, if j is not greater than i, it means j is equals to i, in this case we got a single element as range.
            else
            {
                range += to_string(nums[j]); // nums[i] also works.
            }

            // push range into our answer vector.
            ans.push_back(range);

            // re-initialize range.
            range = "";

            // update i pointer, so that next iteration will start from j+1.
            i = j;
        }

        // return answer.
        return ans;
    }
};

int main(void)
{
    vector<int> nums = {0, 1, 2, 4, 5, 7};

    // Solution.
    Solution obj;
    vector<string> ans = obj.summaryRanges(nums);

    for (int i = 0; i < ans.size(); i++)
    {
        for (auto str : ans[i])
        {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}