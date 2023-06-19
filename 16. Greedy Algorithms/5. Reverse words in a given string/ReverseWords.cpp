#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
    void reverse(string &str)
    {
        int start = 0;
        int end = str.length() - 1;

        while (start <= end)
        {
            swap(str[start++], str[end--]);
        }
    }

public:
    /* Question: Given a String S, reverse the string without reversing its individual words. Words are separated by dots. */
    string reverseWords(string str)
    {
        string ans = "";
        string temp = "";

        for (int i = str.length() - 1; i >= 0; i--)
        {
            if (str[i] == '.')
            {
                reverse(temp);
                ans += temp + '.';

                temp = "";
            }
            else
            {
                temp += str[i];
            }
        }

        reverse(temp);
        ans += temp;

        return ans;
    }
};

int main(void)
{
    string str = "i.like.this.program.very.much";

    // Solution.
    Solution S;
    cout << S.reverseWords(str);
    return 0;
}