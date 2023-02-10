#include <bits/stdc++.h>
using namespace std;

/* ------------------------ Solution Class -------------------------------- */
class Solution
{
private:
public:
    /* Brute Force Approach:- Use Sorting. TC:- O(n log(n)), SC:- O(1) */
    void sortArray_Approach_1(vector<int> &arr)
    {

        // using inbuild sort function.
        sort(arr.begin(), arr.end());
    }

    /* Better Approach:- use counting. TC:- O(n), SC:- O(1) */
    void sortArray_Approach_2(vector<int> &arr)
    {

        // count the frequency of 0's, 1's and 2's.
        int zero = 0;
        int one = 0;
        int two = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == 0)
            {
                zero++;
            }
            else if (arr[i] == 1)
            {
                one++;
            }
            else
            {
                two++;
            }
        }

        // In 2nd traversal of array, we will now over write the first ‘a’ indices / positions in array with ’0’, the next ‘b’ with ‘1’ and the remaining ‘c’ with ‘2’.
        for (int i = 0; i < arr.size(); i++)
        {
            if (zero)
            {
                arr[i] = 0;
                zero--;
            }
            else if (one)
            {
                arr[i] = 1;
                one--;
            }
            else
            {
                arr[i] = 2;
                two--;
            }
        }
    }

    /* Optimized Approach:- Using Dutch National Flag Algorithm. TC:- O(n), SC:- O(1) */
    void sortArray_Approach_3(vector<int> &arr)
    {

        int low = 0, mid = 0, high = arr.size() - 1;
        while (mid <= high)
        {
            if (arr[mid] == 0)
            {
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            }
            else if (arr[mid] == 1)
            {
                mid++;
            }
            else
            {
                // arr[mid] == 2.
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }

    /* Method to print vector. */
    void printVec(vector<int> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    vector<int> arr = {0, 2, 1, 2, 0};

    Solution S;
    S.sortArray_Approach_3(arr);
    S.printVec(arr);
}