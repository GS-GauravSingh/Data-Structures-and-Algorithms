/*
Ques:- Give a string containing either '{' or '}'. This string is valid if all the brackets are balanced. Balanced means for each opening bracket there must be a closing bracket right to it.

Ex:- {}, {}{}, {{}}, {{{}}} these are valid strings.
Ex:- }{, }{}, {}}{{}, {{}}}{ these are not a valid strings.


Note:- for a valid expression,
1. number of opening brackets = number of closing brackets.
2. every closing bracket should have an opening bracket before it
 or every opening bracket must have closing bracket right to it.

So, you need to make this string valid, you can perform following operation, In one operation you can reverse the bracket form '{' to '}' and vice verse.

Return the count of minimum number of brackets you need to reverse so that our string become balanced.

Ex:-   index =>  0 1 2 3
  expression =>  { { { }

in above example, bracket at index 2,3 are alread balanced. In this case we can reverse bracket at index 1. After reverse our string become  { } { }.

So, in this case we reverse only one bracket, our answer is 1.


Approach:-
1. if string length is odd it is impossible to make string valid, return -1, String length must be even.

2. Remove the valid part from the string.
after removing the valid part, you left with 3 types of invalid strings,
1st (all closing brackets) => {{{{{ -- so on.
2nd (all opening brackets) => }}}}} -- so on.
3rd (opening and closing brackets) => so on -- }}}}{{{{ -- so on.

3.the string which is left after removing the valid part is one of the above 3 types.

Count the number of Opening and closing brackets.
ans = ((a+1)/2 + (b+1)/2), a no. of open bracket, b no. of close brackets.

4. return ans = ((a+1)/2 + (b+1)/2);

*/

#include <bits/stdc++.h>
using namespace std;

/* ---------------------- Solution Class -------------------------- */
class Solution
{
private:
public:
    /* Method to find minimum brackets reversal to make this string valid. */
    // Time Complexity :- O(n), n is the length of the string.
    // Space Complexity :- O(n), because we're using stack data structure.
    int findMinimumCost(string &str)
    {
        // If the length of the string is odd, then it is impossible to make this string valid.
        if (str.length() & 1)
        {
            return -1;
        }

        // If the length of the string is even, in this case,
        // 1. remove the valid part (valid pair of curly bracket).
        // 2. after removing the valid part, our string contains invalid curly brackets. Now count he number of opening and closing brackets.
        // 3. ans = ((openBracketCount + 1) / 2 + (closeBracketCount + 1) / 2).

        // Step 1:- removing the valid part.
        stack<char> s;
        for (int i = 0; i < str.length(); i++)
        {
            // picking up the character from the string.
            char ch = str[i];

            // If "ch" is a opening bracket, then push it into stack.
            if (ch == '{')
            {
                s.push(ch);
            }
            else
            {
                // If "ch" is a closing bracket.
                // then , if opening bracket is present at the top of the stack.
                // if present, pop it otherwise puch "ch".
                if (s.empty() && s.top() == '{')
                {
                    s.pop();
                }
                else
                {
                    s.push(ch);
                }
            }
        }

        // at this point our stack contains invalid expression.
        // Now, count the number of opening and closing brackets.
        int closeBracketCount = 0, openBracketCount = 0;
        while (!s.empty())
        {
            if (s.top() == '{')
            {
                openBracketCount++;
            }
            else
            {
                closeBracketCount++;
            }

            s.pop();
        }

        // ans = ((openBracketCount + 1) / 2 + (closeBracketCount + 1) / 2).
        int ans = ((openBracketCount + 1) / 2 + (closeBracketCount + 1) / 2);

        // return answer.
        return ans;
    }
};

int main(void)
{
    string str = "{{{{{{{}}}{{{{";

    // solution.
    Solution S;
    cout << "To make this expression valid, you need to reverse minimum " << S.findMinimumCost(str) << " brackets.";
}