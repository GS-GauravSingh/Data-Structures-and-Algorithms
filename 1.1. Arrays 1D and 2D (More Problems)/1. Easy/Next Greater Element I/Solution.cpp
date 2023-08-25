#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Time Complexity :- O(n), n is the size of vector.
    // Space Complexity :- O(n),because we are using stack data structure.
    vector<int> next_greater_element(vector<int> &arr, int n)
    {
        // vector to store answer.
        vector<int> ans(n, 0);

        // stack.
        stack<int> st;
        // pushing -1 into stack, because we are going to traverse the vector from right,
        // and we know that, for the right most element the next greater element is -1.
        st.push(-1);

        // traverse through the vector from back side.
        for (int i = n - 1; i >= 0; i--)
        {
            // current value.
            int currentValue = arr[i];

            /*
            For currentValue there can be 2 cases,
            Case 1. Stack.top() contains the value which is greater than currentValue (stack.top() > currentValue), and in this case our answer is stack.top().

            Case 2. Stack.top() contains the value which is smaller than or equal to currentValue (stack.top() <= currentValue), and in this case, traverse through the stack and find the greater element and store that greater element in our answer vector.
            */

            // this loop will break when it found the value which is greater than currentValue.
            while (!st.empty() && st.top() != -1 && st.top() <= currentValue)
            {
                // popping the values until we found the value which is greater than currentValue.
                st.pop();
            }

            // above loop will break when it founds the value which is greater than currentValue or it will break when stack.top() == -1 and when the loop breaks at this condition (st.top() == -1), it means there is no element present in stack which is greater than current element (currentValue) and in this case our answer is -1.
            // Now, store that answer value (which is present at stack.top()) into our answer vector.
            ans[i] = st.top();

            // now, push the currentValue into our stack.
            st.push(currentValue);
        }

        return ans;
    }

public:
    // Time Complexity :- O(nums2.size()) + O(nums1.size()).
    // Space Complexity :- O(nums2.size()), because we are using stack and unordered_map data structure.
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {

        // Store the next greater element of all the element present in 'nums2' vector.
        vector<int> nextG = next_greater_element(nums2, nums2.size());

        // Use unordered_map and store the mapping of all element of nums2. Mapping of element with its index.
        // Element -> Index.
        unordered_map<int, int> map;
        for (int i = 0; i < nums2.size(); i++)
        {
            int element = nums2[i];
            map[element] = i;
        }

        // Declare a vector to store answer.
        vector<int> ans;

        // Now, 'nextG' vector contains the next greater element of each element of nums2.
        // Now, traverse the nums1 vector and find the index of nums1[i] in nums2 using unordered_map.
        // Now, nextG vector will store the answer for that index.
        for (int i = 0; i < nums1.size(); i++)
        {
            int idx = map[nums1[i]];
            ans.push_back(nextG[idx]);
        }

        // Finally return answer.
        return ans;
    }
};

int main(void)
{
    vector<int> nums1{4, 1, 2}, nums2{1, 3, 4, 2};

    // Solution.
    Solution obj;
    vector<int> ans = obj.nextGreaterElement(nums1, nums2);

    for (auto i : ans)
        cout << i << " ";
    return 0;
}