/*
Ques:- Given a valid mathematical expression in form of string, return true if the expression contains pair of redundant brackets else return false.

Redundant bracket means, if a subexpression is surrounded by useless or needless bracket.

Example 1:-  (a+b) => does not have any pair of redindant bracket, + operator consumes outer brackets.

Example 2:- ((a+b)) => outer bracket are redundant (useless/needless), inner brackets are consumed by + operator.


Note:-
if any operator is present in b/w a pair of bracket, it means that pair of bracket is not redundant, it's a valid pair.
Ex:- (a+b),  (a * (b + c))

Approach Steps:-
1. While iterting through string if a character is a opening bracket or it's a operator push it into stack.

2. if it is a closing bracket, it means for some previous characters you push into stack it must contain an opening bracket for this closing bracket.

So, you just have to check if any operator is present in b/w these pairs of brackets, if yes, then these bracket are not redundant else these brackets are redundant.

*/
#include <bits/stdc++.h>
using namespace std;

/* ------------------------ Solution Class ---------------------------- */
class Solution
{
private:
    /* Method to check if experssion contains redundant brackets or not.*/
    // Time Complexity :- O(n), n is the length of a string.
    // Space Complexity :- O(n), because we're using stack data structure.
    bool checkForRedundantBrackets(string &str)
    {
        stack<char> s;
        for (int i = 0; i < str.length(); i++)
        {
            // picking the character form string.
            char ch = str[i];

            // if ch is a opening bracket or operator, then push it into stack.
            if (ch == '(' || ch == '+' || ch == '-' || ch == '/' || ch == '*')
            {
                s.push(ch);
            }
            else
            {
                // if "ch" is a closing bracket.
                // If this pair of bracket are not redundant, there must be an operator present in b/w these pair of brackets.
                // if there is no operator present in b/w these brackets, it means this pair of brackets are redundant.
                if (ch == ')')
                {
                    bool isRedundant = true;
                    while (s.empty() || s.top() != '(')
                    {
                        if (s.top() == '+' || s.top() == '-' || s.top() == '/' || s.top() == '*')
                        {
                            isRedundant = false;
                        }
                        s.pop();
                    }

                    if (isRedundant == true)
                    {
                        // if isRedundant is true, it means redundant backets are present.
                        // return true.
                        return true;
                    }

                    // if isRedundant is false, it means current pair of bracket is not redundant,
                    // remove the opening bracket from stack and continue the process.
                    // because this loop will terminate when it find an opening bracket. So, we have to remove this opening bracket.
                    s.pop();
                }
            }
        }
        // at this point, if the program does not return anything, it means the expression does not contain any redundant brackets. So, return false.
        return false;
    }

public:
    /* Main method to check for redundant brackets. */
    bool findRedundantBrackets(string &str)
    {
        return checkForRedundantBrackets(str);
    }
};

int main(void)
{
    string str = "((a+b))";

    // solution.
    Solution S;
    if (S.findRedundantBrackets(str))
    {
        cout << "Redundant brackets present.\n";
    }
    else
    {
        cout << "Redundant brackets not present.\n";
    }
}