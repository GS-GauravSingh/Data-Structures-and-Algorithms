/*
Question :-
Implement the RandomizedSet class:

RandomizedSet() Initializes the RandomizedSet object.
bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.
You must implement the functions of the class such that each function works in average O(1) time complexity.
*/
#include <bits/stdc++.h>
using namespace std;

/*------------------------------ Solution Class -----------------------------*/
class RandomizedSet
{
private:
    // Data Members
    unordered_map<int, int> mpp;
    vector<int> arr;

public:
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        // if value is already present, return false.
        if (mpp.find(val) != mpp.end())
        {
            return false;
        }

        // if value is not present, insert it and return true.
        arr.push_back(val);
        mpp[val] = arr.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        auto it = mpp.find(val);
        // if value is not present, return false.
        if (it == mpp.end())
        {
            return false;
        }

        // if value is present,then remove it and return true.

        int idx = it->second;  // index of value, which we have to remove.
        arr[idx] = arr.back(); // at index of value which we have to delete, replace the value with last value present at array.
        arr.pop_back();        // pop the last value.

        mpp[arr[idx]] = idx; // update the index of last value in map.
        mpp.erase(val);      // erase value which we have to delete from map.
        return true;
    }

    int getRandom()
    {
        int n = arr.size();
        int randomElement = arr[rand() % n];
        return randomElement;
    }
};
/*-------------------------- Solution Class Ends Here. ------------------------- */

int main()
{
    RandomizedSet *obj = new RandomizedSet();

    int val = 5;
    bool param_1 = obj->insert(val);
    // bool param_2 = obj->remove(val);
    int param_3 = obj->getRandom();
    cout<<param_3;
}