#include <bits/stdc++.h>
using namespace std;

/* --------------------------- Solution Class ------------------------------- */
class Solution
{
private:
public:
    /* Brute Force Approach :- Using nested loops. */
    // Time Complexity :- O(n^2), n is the size of vector.
    // Space Complexity :- O(1), O(n) if we consider the size of answer vector.
    vector<int> nextGreaterElement_BruteForce(vector<int> &arr, int n)
    {
        // vector to store answer.
        vector<int> ans(n, 0);

        // iterate through the vector.
        for (int i = 0; i < n; i++)
        {
            // current value.
            int currentValue = arr[i];

            // flag to check, if we found the value greater than current value.
            bool greaterValueFound = false;

            for (int j = i + 1; j < n; j++)
            {
                // next value
                int nextValue = arr[j];

                // while iterating through the vector, the first value we found which is greater than currentValue. We have to store that greater value in our answer.
                // if we don't found any value which is greater than currentValue, in this case our answer is -1.
                if (nextValue > currentValue)
                {
                    greaterValueFound = true;
                    ans[i] = nextValue;
                    break;
                }
            }

            // if we don't found any value which is greater than currentValue, in this case our flag (greaterValueFound) is false and our answer is -1.
            if (greaterValueFound == false)
            {
                ans[i] = -1;
            }
        }

        return ans;
    }

    /* Optimized Approach :- Using Stack Data Structure. */
    // Time Complexity :- O(n), n is the size of vector.
    // Space Complexity :- O(n),because we are using stack data structure.
    vector<int> nextGreaterElement_Optimized(vector<int> &arr, int n)
    {
        // vector to store answer.
        vector<int> ans(n,0);

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
    vector<int> arr = {2, 1, 4, 3};

    // Solution.
    Solution S;
    // vector<int> ans = S.nextGreaterElement_BruteForce(arr, arr.size());
    vector<int> ans = S.nextGreaterElement_Optimized(arr, arr.size());
    S.printVec(ans);
}