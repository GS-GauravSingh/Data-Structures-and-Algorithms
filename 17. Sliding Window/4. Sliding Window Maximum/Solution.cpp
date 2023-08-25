#include <bits/stdc++.h>
using namespace std;

class Solution
{
    /* Brute Force Appriach: Generate all subarrys of size 'k' and then find the maximum element of each subarray. */
    // Time Compelxity: O((N - K + 1) * K), where 'N' is the size of the subarray and 'K' si the window size.
    // Space Complexity: O(1).
    vector<int> maxSlidingWindow_BruteForce(vector<int> &nums, int K)
    {

        // size of vector.
        int N = nums.size();

        // vector to store maximum element of each subarray of size 'k'.
        vector<int> ans;

        // Now, there can be total (N - K + 1) subarrays of size 'k'.
        for (int i = 0; i < (N - K + 1); i++)
        {
            // variable to calculate the maximum element of current subarray of size 'k'.
            int maxElement = INT_MIN;

            // Traverse through the current window of size 'k'.
            for (int j = 0; j < K; j++)
            {
                // Compute the maximum element of this window.
                maxElement = max(maxElement, nums[i + j]);
            }

            // Store the maximum element of this subarray of size 'k' into a vector.
            ans.push_back(maxElement);
        }

        // return the answer vector.
        return ans;
    }

    /* Optimized Approach: Using Sliding Window and Max Heap. */
    // Time Complexity: O(N log(k)), where 'N' is the size of the nums vector.
    // Space Complexity: O(k), space used by max heap..
    vector<int> maxSlidingWindow_Optimized_1(vector<int> &nums, int K)
    {
        // size of vector.
        int N = nums.size();

        // vector to store maximum element of each subarray of size 'k'.
        vector<int> ans;

        // Declare a Max Heap.
        // Max Heap will help us to keep track of the maximum elements.
        priority_queue<pair<int, int>> maxHeap;

        // Pointers.
        // 'Start' pointer will represent the starting point/index of 'k' size window.
        int start = 0;

        // 'End' pointer will represent the ending point/index of 'k' size window.
        int end = 0;

        // We have to run a loop while end < N.
        while (end < N)
        {
            // Push the current element into the max heap.
            // This is a max heap, so the maximum element will be present at the top of the max heap.
            maxHeap.push({nums[end], end});

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

                // when "windowSize == K", it means we hit the window size i.e., k.
                // and the top element of max heap will have to maximum element of current subarray of size 'k'.
                pair<int, int> top = maxHeap.top();

                // Maximum Element.
                int maxElement = top.first;

                // Index of Maximum Element.
                int maxElementIdx = top.second;

                // Now, we have the index of maximum element of current window.
                // Now, we just have to check whether this index 'maxElement' is in the range of current window or not.
                // If, yes, then this is the maximum element of current window of size 'k'.
                if (maxElementIdx >= start && maxElementIdx <= end)
                {
                    // Store this maximum element.
                    ans.push_back(nums[maxElementIdx]);

                    // Shift this window ahead.
                    start++;
                    end++;
                }

                // But, this maximumElement is not in the range of current window, it means this element is not the maximum element of this current window.
                else
                {
                    // Just remove all the maximum elements of previous windows.
                    while (maxHeap.top().second < start)
                    {
                        maxHeap.pop();
                    }

                    // After remove all the maximum elements of previous windows.
                    // Now, maxHeap.top() will have the maximum element of current window.
                    pair<int, int> top = maxHeap.top();
                    int maxElement = top.first;
                    int maxElementIdx = top.second;

                    ans.push_back(nums[maxElementIdx]);

                    // Shift this window ahead.
                    start++;
                    end++;
                }
            }
        }

        // return the answer vector.
        return ans;
    }

    /* Optimized Approach: Using Sliding Window and Dequeue. */
    // Time Complexity: O(N), where 'N' is the size of the nums vector.
    // Space Complexity: O(k), space used by max heap..
    vector<int> maxSlidingWindow_Optimized_2(vector<int> &nums, int K)
    {
        // size of vector.
        int N = nums.size();

        // vector to store maximum element of each subarray of size 'k'.
        vector<int> ans;

        // Declare a Dequeue.
        // Dequeue will help us to keep track of the maximum elements.
        deque<pair<int, int>> dq;

        // Pointers.
        // 'Start' pointer will represent the starting point/index of 'k' size window.
        int start = 0;

        // 'End' pointer will represent the ending point/index of 'k' size window.
        int end = 0;

        // We have to run a loop while end < N.
        while (end < N)
        {
            // Store the elements in dequeue in descending order.
            while (!dq.empty() && dq.back().first < nums[end])
            {
                dq.pop_back();
            }
            dq.push_back({nums[end], end});

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

                // when "windowSize == K", it means we hit the window size i.e., k.
                // and the front element of dequeue will have to maximum element of current subarray of size 'k' because in dequeue we have store all the elements in decreasing order. So, maximum element will be at the fron of the dequeue.
                pair<int, int> front = dq.front();

                // Maximum Element.
                int maxElement = front.first;

                // Index of Maximum Element.
                int maxElementIdx = front.second;

                // Now, we have the index of maximum element of current window.
                // Now, we just have to check whether this index 'maxElement' is in the range of current window or not.
                // If, yes, then this is the maximum element of current window of size 'k'.
                if (maxElementIdx >= start && maxElementIdx <= end)
                {
                    // Store this maximum element.
                    ans.push_back(nums[maxElementIdx]);

                    // Shift this window ahead.
                    start++;
                    end++;
                }

                // But, this maximumElement is not in the range of current window, it means this element is not the maximum element of this current window.
                else
                {
                    // Just remove all the maximum elements of previous windows.
                    while (dq.front().second < start)
                    {
                        dq.pop_front();
                    }

                    // After remove all the maximum elements of previous windows.
                    // Now, dq.front() will have the maximum element of current window.
                    pair<int, int> front = dq.front();
                    int maxElement = front.first;
                    int maxElementIdx = front.second;

                    ans.push_back(nums[maxElementIdx]);

                    // Shift this window ahead.
                    start++;
                    end++;
                }
            }
        }

        // return the answer vector.
        return ans;
    }

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {

        // // Brute Force Approach.
        // return maxSlidingWindow_BruteForce(nums, k);

        // // Optimized Approach 1.
        // return maxSlidingWindow_Optimized_1(nums, k);

        // Optimized Approach 2.
        return maxSlidingWindow_Optimized_2(nums, k);
    }
};

int main(void)
{
    vector<int> nums{3, 2, -1, -3, 5, 3, 6, 7};
    int k = 3;

    // Solution.
    Solution obj;
    vector<int> ans = obj.maxSlidingWindow(nums, k);
    for (int i : ans)
    {
        cout << i << " ";
    }

    return 0;
}