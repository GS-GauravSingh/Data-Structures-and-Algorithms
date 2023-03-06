/*
It's an Important question but the solution of this is very easy.

Approach:- Iterate through the string, while iterating, if it is a opening bracket push it into stack and when a closing bracket come, you have to check if the correspond opening bracket is present on the top of stack, if it is present pop the top element else return not balanced.

At the end if your stack become empty means string is balanced else not.

Example:- I/O string:- [ { ( ) } ]
sol:-
Iterate through the string and if a opening bracket come push it into stack.

    Stack
      (
      {
      [
 and when closing bracket came we have to check if the correspond opening bracket of that closing barcket is present on the top of the stack
 or not.

  (  is barcket ke correspong closing brack ) ye hoga.
  [  is barcket ke correspong closing brack ] ye hoga.
  {  is barcket ke correspong closing brack } ye hoga.

Closing bracket came,

    str[i] == ) and stack.top() == (, means opening bracket is present.
    pop the top element.

    Stack
      {
      [


    str[i] == } and stack.top() == {, means opening bracket is present.
    pop the top element.

    Stack
      [

    str[i] == ] and stack.top() == [, means opening bracket is present.
    pop the top element.

    Stack

Now stack is empty means expressiong is balanced.


*/

#include <bits/stdc++.h>
#include "../../Stack Implementation/StackImplementationUsingArray.h"
using namespace std;

/* --------------- Solution class ---------------------- */
class Solution
{
private:
    /* Method to check is a string is a valid parenthesis or not. */
    // Time Complexity :- O(n), n is the length of a string.
    // Space Complexity :- O(n), because we are using stack data structure.
    bool checkForValidParanthesis(string &str)
    {
        // I am using my own implementation of stack.
        // You can use stl implementation of stack also.
        Stack<int> s;

        // Iterate through the string.
        for (int i = 0; i < str.length(); i++)
        {
            // picking the character from the string.
            char ch = str[i];

            // if ch (ch = str[i]) is opening bracket, then push "ch" into stack.
            if (ch == '(' || ch == '[' || ch == '{')
            {
                s.push(ch);
            }

            // if "ch" is not a opening bracket, it means it's a closing bracket.
            // Now, check for correspond opening bracket on the top of the stack,
            //  if opening bracket is present, pop the top element and continue the process.
            //  else if opening bracket is not present, then return false, expression Not Balanced.
            else
            {
                // But before checking the top element of the stack, first check, if the stack is empty or not.
                // Suppose if an expression contains only closing brackets (ex: str = "{{{{"), then in this case your stack is empty and when you try to check the top element it will give segmentation fault error.
                if (!s.isEmpty())
                {
                    if ((ch == ')' && s.top() == '(') || (ch == ']' && s.top() == '[') || (ch == '}' && s.top() == '{'))
                    {
                        // if opening brack is present, then pop the top element.
                        s.pop();
                    }
                    else
                    {
                        // if there is no opening bracked present at top of the stack,
                        // then it is not a balanced expression, return false.
                        return false;
                    }
                }
                else
                {
                    // if expression contains all closing brackets,
                    // then it's not a balanced expression, return false.
                    return false;
                }
            }
        }

        // At the end, if the stack is empty means expression is balanced, return true otherwise return false.
        if (s.isEmpty())
        {
            return true;
        }
        return false;
    }

public:
    /* Main Method to check is a string is a valid parenthesis or not. */
    bool isValid(string str)
    {
        return checkForValidParanthesis(str);
    }
};

int main(void)
{
    string str1 = "{{{[[[((()))]]]}}}";  // valid
    string str2 = "{{[()]}}{{{([)])}}}"; // not valid.

    // Solution.
    Solution S;

    if (S.isValid(str1))
    {
        cout << "Experssion is Valid.\n";
    }
    else
    {
        cout << "Experssion is not Valid.\n";
    }
}