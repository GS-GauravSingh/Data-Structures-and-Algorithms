#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
    /* Brute Force Appriach: Generate all subarrys of size 'k' and then find the first -ve integer in evry window of size 'k'. */
    // Time Compelxity: O((N - K + 1) * K), where 'N' is the size of the subarray and 'K' si the window size.
    // Space Complexity: O(1).
    vector<long long> printFirstNegativeInteger_BruteForce(long long int arr[], long long int N, long long int K)
    {
        // vector to store answer.
        vector<long long> ans;

        // Now, there can be total (N - K + 1) subarrays of size 'k'.
        for (int i = 0; i < (N - K + 1); i++)
        {
            // boolean variable to check whether there is -ve element present in this current subaarys of size 'k' or not.
            bool negPresent = false;

            // Traverse through the current window of size 'k'.
            for (int j = 0; j < K; j++)
            {
                // As soon as we found the fist -ve integer in this subarrays of size 'k'.
                // Store this -ve element and then break this loop and move to next subarray.
                if (arr[i + j] < 0)
                {
                    // Mark the flahe as true, because negative element is present.
                    negPresent = true;

                    // store this negative element.
                    ans.push_back(arr[i + j]);

                    // break the loop and move to next subarray.
                    break;
                }
            }

            // Now, if -ve element is not present in this current subarray of size 'k', then in this case we have to push "0" in our answer vector, where "0" represents, there is no -ve integer in this current window.
            if (negPresent == false)
            {
                ans.push_back(0);
            }
        }

        // return answer.
        return ans;
    }

    /* Optimized Approach: Using Sliding Window. */
    // Time Complexity: O(N), where 'N' si the size of the array.
    // Space Complexity: O(K), space used by dequeue.
    vector<long long> printFirstNegativeInteger_Optimized(long long int arr[], long long int N, long long int K)
    {
        // vector to store answer.
        vector<long long> ans;

        // Declare a dequeue of size 'k'. This is used to stroe indexes -ve elements.
        // I am using dequeue data structure because we can perform insertion and deletion from both the ends (front and rear) in dequeue data structure.
        deque<long long> dq;

        // Pointers.
        // 'Start' pointer will represent the starting point/index of 'k' size window.
        long long int start = 0;

        // 'End' pointer will represent the ending point/index of 'k' size window.
        long long int end = 0;

        // We have to run a loop while end < N.
        while (end < N)
        {
            // If current element is negative, then push the index of this element into the dequeue.
            if (arr[end] < 0)
            {
                dq.push_back(end);
            }

            // 'windowSize' represent the total number of element in current window.
            // 'k' sized window has 'k' number of elements and 'windowSize' sized window has 'windowSize' number of elements.
            int windowSize = end - start + 1;

            // If 'windowSize' is less then 'k'.
            if (windowSize < K)
            {
                end++;
            }

            // when "windowSize == K", it means we hit the window size i.e., k.
            else if (windowSize == K)
            {
                // If our dequeue is empty, it means there is no negative element present in this current window.
                if (dq.empty())
                {
                    // In this case, push 0 into answer vector.
                    ans.push_back(0);

                    // Shift this window ahead.
                    start++;
                    end++;
                }
                else
                {
                    // Now, if our dequeue is not empty, then dequeue will contain the indexes of -ve elements.
                    // dq.front(), will have the index of first negative element.
                    // Now, we just have to check whether this index 'dq.front()' is in the range of current window or not.
                    // If yes, then this element is the first -ve integer of this window.
                    int indexOfNegative = dq.front();
                    if (indexOfNegative >= start && indexOfNegative <= end)
                    {
                        ans.push_back(arr[indexOfNegative]);
                    }

                    // Shift this window ahead.
                    start++;
                    end++;

                    // Now, after shifting window ahead, just check whether 'dq.front()' still lie in this range of current window or not.
                    // If yes, then this is the first -ve element of current window.
                    // Otherwise this -ve element belongs to previous window and in this case we have to pop this element from dequeue.
                    if (indexOfNegative < start)
                    {
                        dq.pop_front();
                    }
                }
            }
        }

        // return answer.
        return ans;
    }

public:
    vector<long long> printFirstNegativeInteger(long long int arr[], long long int N, long long int K)
    {
        // // Brute Force Approach.
        // return printFirstNegativeInteger_BruteForce(arr, N, K);

        // Optimized Approach.
        return printFirstNegativeInteger_Optimized(arr, N, K);
    }
};

int main(void)
{

    long long arr[] = {-8, 2, 3, -6, 10};
    long long K = 2;
    long long N = sizeof(arr) / sizeof(arr[0]);

    // Solution.
    Solution obj;
    vector<long long> ans = obj.printFirstNegativeInteger(arr, N, K);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}