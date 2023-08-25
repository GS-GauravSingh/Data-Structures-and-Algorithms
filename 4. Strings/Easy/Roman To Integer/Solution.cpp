#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Time Complexity: O(n), where 'n' is the length of the string.
    // Space Complexity: O(1), because size of map does not depend on the input. Therefore, the space used by the map is proportional to the number of unique Roman numerals, which is a constant value.
    int romanToInt(string str)
    {
        // Storing the mapping of Roman Numeral to Integer.
        unordered_map<string, int> map;
        map["I"] = 1;
        map["V"] = 5;
        map["X"] = 10;
        map["L"] = 50;
        map["C"] = 100;
        map["D"] = 500;
        map["M"] = 1000;
        map["IV"] = 4;
        map["IX"] = 9;
        map["XL"] = 40;
        map["XC"] = 90;
        map["CD"] = 400;
        map["CM"] = 900;

        // variable to store answer.
        int ans = 0;

        // Traverse through the string.
        for (int i = 0; i < str.length(); i++)
        {
            if (i + 1 < str.length() && str[i] == 'I' && str[i + 1] == 'V')
            {
                ans = ans + map["IV"];
                i++;
            }
            else if (i + 1 < str.length() && str[i] == 'I' && str[i + 1] == 'X')
            {
                ans = ans + map["IX"];
                i++;
            }
            else if (i + 1 < str.length() && str[i] == 'X' && str[i + 1] == 'L')
            {
                ans = ans + map["XL"];
                i++;
            }
            else if (i + 1 < str.length() && str[i] == 'X' && str[i + 1] == 'C')
            {
                ans = ans + map["XC"];
                i++;
            }
            else if (i + 1 < str.length() && str[i] == 'C' && str[i + 1] == 'D')
            {
                ans = ans + map["CD"];
                i++;
            }
            else if (i + 1 < str.length() && str[i] == 'C' && str[i + 1] == 'M')
            {
                ans = ans + map["CM"];
                i++;
            }
            else
            {
                string currChar;
                currChar.push_back(str[i]); // Because my key is of type String.
                ans = ans + map[currChar];
            }
        }

        return ans;
    }
};

int main(void)
{
    string str = "MCMXCIV";

    // Solution.
    Solution obj;
    cout << str << " = " << obj.romanToInt(str) << ".";
    return 0;
}