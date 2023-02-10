#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
public:
    /* Method to rotate array by one element to the right. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(1)
    void rotateByOne(vector<int> &arr)
    {
        // size of array.
        int n = arr.size();

        // storing last element.
        int lastElement = arr[n - 1];

        // shif all elements to the right by one place.
        for (int i = n - 1; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = lastElement;
    }

    /* Method to print array. */
    void print(vector<int> arr)
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
    vector<int> arr = {1, 2, 3, 4, 5};

    Solution S;
    cout << "Before Rotation :- ";
    S.print(arr);

    cout << "After Rotation :- ";
    S.rotateByOne(arr);
    S.print(arr);
}