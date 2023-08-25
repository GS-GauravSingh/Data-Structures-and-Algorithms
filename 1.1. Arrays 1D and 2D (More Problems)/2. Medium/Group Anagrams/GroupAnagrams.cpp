#include <bits/stdc++.h>
using namespace std;

class Solution
{
    /* Counting sort algorithm used in approach 2. */
    // Time Complexity: O(n) + O(26), where 'n' is the length of the string 'str'.
    // Space Complexity: O(26), space used by 'freq' vector.
    string countingSort(string str)
    {
        // Create a frequency array of size 26.
        vector<int> freq(26);

        // Traverse the string and increment the frequence of each character in str.
        for (auto ch : str)
        {
            freq[ch - 'a']++;
        }

        // string to store sorted string.
        string temp;

        // Traverse the 'freq' vector and store the characters in sorted order.
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] != 0)
            {
                // store this character 'freq[i]' times.
                while (freq[i]--)
                    temp.push_back(i + 'a');
            }
        }

        // finally return the sorted string.
        return temp;
    }

    /* Approach: Using sorting and unordered_map.

    Example: strs = {"eat","tea","tan","ate","nat","bat"};

    Dry-Run:

    Step 1: Traverse the original vector (strs) and sort each word.
    after sorting, the array would look like this, {"aet","aet","ant","aet","ant","abt"};

    Original array:                 {"eat","tea","tan","ate","nat","bat"};
    Array after sorting each word:  {"aet","aet","ant","aet","ant","abt"};

    Step 2: Create a map and create a mapping like this.

    >> Mapping:
    aet -> eat, tea, ate.
    abt -> bat.
    ant -> nat, tan.

    Now, if you observe carefully, the strings "eat", "tea" and "ate", after sorting these strings, the sorted part of these string are same.

    eat -> after sorting -> it becomes "ate".
    tea -> after sorting -> it becomes "ate".
    ate -> after sorting -> it becomes "ate".

    and if you observe carefully, the strings "nat" and "tan", after sorting these strings, the sorted part of these string are same.

    nat -> after sorting -> it becomes "ant".
    tan -> after sorting -> it becomes "ant".

    and if you observe carefully, the string 'bat'.

    bat -> after sorting -> it becomes "abt"

    >> Now the point is, if you use sorted words as a 'key' and corresponds to these 'key' you can store all the string words, that is have same sorted parts.

    After this the map would look like this,

    Map:

    key   --->  Value
    ---------------
    "aet" --->  {"eat", "tea", "ate"}
    "abt" --->  {"bat"}
    "ant" --->  {"nat", "tan"}

    And after store the mapping, all the anagrams are grouped and your answer is ready.
    Traverse the map and store all the group anagrams into a separate vector.
    */

    // Time Complexity: O(n * mlog(m)), where 'n' is the number of string in strs vector , and m is the length of a particular string.
    // Space Complexity: O(n*m) + O(n*m), space used by ans vector and unordered_map.
    vector<vector<string>> groupAnagrams_Approach_1(vector<string> &strs)
    {

        // size of the strs vector.
        int n = strs.size();

        // vector to store answer.
        vector<vector<string>> ans;

        // Base Case
        if (n == 0)
        {
            return ans;
        }
        if (n == 1)
        {
            ans.push_back(strs);
            return ans;
        }

        /*
        Step 1: Traverse the original vector (strs) and sort each word.
        after sorting, the array would look like this, {"aet","aet","ant","aet","ant","abt"};

        Original array:                 {"eat","tea","tan","ate","nat","bat"};
        Array after sorting each word:  {"aet","aet","ant","aet","ant","abt"};

        Step 2: Create a map and create a mapping like this.

        >> Mapping:
        aet -> eat, tea, ate.
        abt -> bat.
        ant -> nat, tan.
        */
        unordered_map<string, vector<string>> map;
        for (auto str : strs)
        {
            string temp = str;
            sort(temp.begin(), temp.end());
            map[temp].push_back(str);
        }

        // Traverse the map and store the answer.
        for (auto it : map)
        {
            ans.push_back(it.second);
        }

        // return answer.
        return ans;
    }

    /* A Small Optimization we can done is : Since the input only contains lower-case alphabets, so we can use counting sort algorithm instead of in-built 'sort()'.

    Time complexity of in-built 'sort()' is O(n log(n)).
    Time complexity of counting sort is O(n) + O(26). See the TC decreased when we used counting sort.
    */

    // Time Complexity: O(n) * (O(m) + O(26)), where 'n' is the number of string in strs vector , and m is the length of a particular string.
    // Space Complexity: O(n*m) + O(n*m), space used by ans vector and unordered_map.
    vector<vector<string>> groupAnagrams_Approach_2(vector<string> &strs)
    {

        // size of the strs vector.
        int n = strs.size();

        // vector to store answer.
        vector<vector<string>> ans;

        // Base Case
        if (n == 0)
        {
            return ans;
        }
        if (n == 1)
        {
            ans.push_back(strs);
            return ans;
        }

        /*
        Step 1: Traverse the original vector (strs) and sort each word.
        after sorting, the array would look like this, {"aet","aet","ant","aet","ant","abt"};

        Original array:                 {"eat","tea","tan","ate","nat","bat"};
        Array after sorting each word:  {"aet","aet","ant","aet","ant","abt"};

        Step 2: Create a map and create a mapping like this.

        >> Mapping:
        aet -> eat, tea, ate.
        abt -> bat.
        ant -> nat, tan.
        */
        unordered_map<string, vector<string>> map;
        for (auto str : strs)
        {
            string temp = countingSort(str);
            map[temp].push_back(str);
        }

        // Traverse the map and store the answer.
        for (auto it : map)
        {
            ans.push_back(it.second);
        }

        // return answer.
        return ans;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {

        // Approach 1: using unordered_map and in-built 'sort()' function.
        // return groupAnagrams_Approach_1(strs);

        // Approach 2: using unordered_map and counting sort.
        return groupAnagrams_Approach_2(strs);
    }
};

int main(void)
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    // Solution.
    Solution obj;
    vector<vector<string>> ans = obj.groupAnagrams(strs);

    for (auto row : ans)
    {
        for (auto col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }
    return 0;
}