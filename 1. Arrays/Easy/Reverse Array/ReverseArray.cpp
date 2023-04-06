#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

/*------------------------------ Solution Class -----------------------------*/
class Solution
{
public:
    // Approach 1 :- Using another array..
    // Time Complexity:- O(n), n is the size of vector.
    // Space Complexity:- O(n)
    void reverse_Approach_1(vector<int> &nums)
    {
        // copy all the elements of "nums" into "arr" array in reverse order. 
        vector<int> arr;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            arr.push_back(nums[i]);
        }

        // copy back all element of arr into original array.
        for (int i = 0; i < arr.size(); i++)
        {
            nums[i] = arr[i];
        }

        
    }
    // Approach 2 :- Using 2 pointers.
    // Time Complexity:- O(n), n is the size of vector.
    // Space Complexity:- O(1)
    void reverse_Approach_2(vector<int> &nums)
    {
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end)
        {
            swap(nums[start++], nums[end--]);
        }
    }

    /* Method to print vector. */
    void print(vector<int> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
/*-------------------------- Solution Class Ends Here. ------------------------- */
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    Solution s;
    s.reverse_Approach_1(arr);
    s.print(arr);
}
