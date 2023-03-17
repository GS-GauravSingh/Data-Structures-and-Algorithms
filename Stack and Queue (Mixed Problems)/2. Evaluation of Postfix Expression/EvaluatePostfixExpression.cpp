#include <bits/stdc++.h>
using namespace std;

/* ------------------------- Solution Class ---------------------------------- */
class Solution
{
private:
public:
    /* Method to evaluate postfix expression. */
    int evaluatePostfix(string str)
    {
        // stack of integer.
        stack<int> st;

        // traverse through the postfix expression (str).
        for (char ch : str)
        {
            // Checking, If the character "ch" is a digit (0 to 9) or an operator (+, -, /, *).
            if (isdigit(ch))
            {
                // If the character "ch" is a digit (0 to 9), then push it into the stack.
                st.push(ch - '0'); 
            }
            else{
                // If the character "ch" is not a digit (0 to 9), it means it is an operator (+, -, /, *).
                // In this case, extract two elements from the stack and perform the operation according to the operator (ch), and push the result into the stack.

                // Note :- 
                // 1. the first element you extract from the top of the stack, in the expression place this element on the right of the operator.
                // 2. the second element you extract from the top of the stack, in the expression place this element on the left of the operator.
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();

                // performing operation according to operator (ch).
                // result = num2 operator num1.
                int result = 0;
                switch (ch)
                {
                case '+':
                    result = num2 + num1;
                    break;
                case '-':
                    result = num2 - num1;
                    break;
                case '/':
                    result = num2 / num1;
                    break;
                case '*':
                    result = num2 * num1;
                    break;
                } 

                // push the result int the stack.
                st.push(result);
            }
        }

        return st.top();
    }
};

int main(void)
{
    string postfixExpression = "231*+9-";

    Solution S;
    cout<<S.evaluatePostfix(postfixExpression);
}