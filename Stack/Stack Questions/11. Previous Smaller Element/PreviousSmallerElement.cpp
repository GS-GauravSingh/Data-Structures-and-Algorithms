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
    vector<int> previousSmallerElement_BruteForce(vector<int> &arr, int n)
    {
        // vector to store answer.
        vector<int> ans(n, 0);

        // iterate through the vector.
        for (int i = n; i >= 0; i--)
        {
            // current value.
            int currentValue = arr[i];

            // flag to check, if we found the value smaller than current value.
            bool smallerValueFound = false;

            for (int j = i - 1; j >= 0; j--)
            {
                // previous value
                int previousValue = arr[j];

                // while iterating through the vector, the first value we found which is smaller than currentValue. We have to store that smaller value in our answer.
                // if we don't found any value which is smaller thet currentValue, in this case our answer is -1.
                if (previousValue < currentValue)
                {
                    smallerValueFound = true;
                    ans[i] = previousValue;
                    break;
                }
            }

            // if we don't found any value which is smaller thet currentValue, in this case our flag (smallerValueFoundanswer) is false and our answer is -1.
            if (smallerValueFound == false)
            {
                ans[i] = -1;
            }
        }

        return ans;
    }

    /* Optimized Approach :- Using Stack Data Structure. */
    // Time Complexity :- O(n), n is the size of vector.
    // Space Complexity :- O(n),because we are using stack data structure.
    vector<int> previousSmallerElement_Optimized(vector<int> &arr, int n)
    {
        // vector to store answer.
        vector<int> ans(n,0);

        // stack.
        stack<int> st;
        // pushing -1 into stack, because we are going to traverse the vector from left,
        // and we know that, for the left most element the previous smaller element is -1.
        st.push(-1);

        // traverse through the vector.
        for (int i = 0; i < n; i++)
        {
            // current value.
            int currentValue = arr[i];

            /*
            For currentValue there can be 2 cases,
            Case 1. Stack.top() contains the value which is smaller than currentValue (stack.top() < currentValue), and in this case our answer is stack.top().

            Case 2. Stack.top() contains the value which is greater than or equal to currentValue (stack.top() >= currentValue), and in this traverse through the stack and find the smaller element and store that smaller element in our answer vector.
            */

            // this loop will break when it found the value which is smaller than currentValue.
            // and this loop will only run if st.top() contains the value which is greater than or equal to currentValue, otherwise it will not run.
            while (!st.empty() && st.top() >= currentValue)
            {
                // popping the values until we found the value which is smaller than currentValue.
                st.pop();
            }

            // above loop will break when it founds the value which is smaller than currentValue.
            // Now, store that smaller value (which is present at stack.top()) into our answer vector.
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
    // vector<int> ans = S.previousSmallerElement_BruteForce(arr, arr.size());
    vector<int> ans = S.previousSmallerElement_Optimized(arr, arr.size());
    S.printVec(ans);
}