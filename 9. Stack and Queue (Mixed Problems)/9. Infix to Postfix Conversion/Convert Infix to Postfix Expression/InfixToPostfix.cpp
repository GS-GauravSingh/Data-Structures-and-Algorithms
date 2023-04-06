#include <bits/stdc++.h>
using namespace std;

/* ----------------------- Solution Class ------------------------------ */
class Solution
{
private:
    /* Methopd to check precendece of operators. */
    int precendeceOf(char ch)
    {
        // 0 to 2, means lower precendece to higher precedence.
        switch (ch)
        {
        case '^':
            return 0;
            break;
        case '+':
            return 1;
            break;
        case '-':
            return 1;
            break;
        case '/':
            return 2;
            break;
        case '*':
            return 2;
            break;

        default:
            break;
        }

        return -1;
    }

public:
    /* Method to convert Infix Expression to Postfix Expression. */
    // Time Complexity:- O(n). n is the lenght of the InfixExpression string.
    // Space Complexity:- O(n), because we are using an additional data structure stack.
    string ConvertInfixExpressionToPostfixExpression(string infixExpression)
    {
        // declaring a stack of characters.
        stack<char> st;

        // string to store post expression of the given infix expression.
        string postFixExpression = "";

        // traversing the infix expression.
        for (char ch : infixExpression)
        {
            /*
            While traversing the infix expression, we must encounter 4 things,
            1. If character "ch" is a opening parenthesis ("(").
            2. If character "ch" is a closing parenthesis (")").
            3. If character "ch" is a operator (+,-,/,*).
            4. If character "ch" is a operand.
            */

            // If character "ch" is an Opening parenthesis, then push it into the stack.
            if (ch == '(')
            {
                st.push(ch);
            }

            // else if character "ch" is an Operand, then push it into the postFixExpression string.
            else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
            {
                postFixExpression.push_back(ch);
            }

            // else if character "ch" is an Operator then
            else if (ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '^')
            {
                // If stack is empty, then push "ch" into the stack.
                if(st.empty())
                {
                    st.push(ch);
                }

                /*
                Else, if stack is not empty, in this we have 2 cases,

                Case 1 :- stack.top() will contain an Opening Parenthesis ("("). In this case simply push "ch" into the stack.

                Case 2 :- stack.top() will contain an Operator (+,-,/,*,^). In this case compare "ch" with operator present at stack.top().

                Note :- We have to maintain higher precedence to lower precedence into our stack. It means stack.top() will contain the operator having higher precedence and rest of the elements are in decreasing order of precedence.
                Ex:- stack 
                       *
                       +
                       ^
                
                So, 
                if(precedenceOf(ch) > precedenceOf(stack.top()))
                {
                    simply push "ch" into the stack.
                }
                else (precedenceOf(ch) <= precedenceOf(stack.top()))
                {
                    store and pop until the stack is not empty or you find the operator having precedence lower than precedence of ch and then push "ch" into the stack.
                }
                */
                else{

                    if(precendeceOf(ch) > precendeceOf(st.top()))
                    {
                        st.push(ch);
                    }
                    else{
                        // precendeceOf(ch) <= precendeceOf(st.top())
                        while (!st.empty() && precendeceOf(ch) <= precendeceOf(st.top()))
                        {
                            postFixExpression.push_back(st.top());
                            st.pop();
                        }

                        st.push(ch);
                    }
                }
            }
            // else character "ch" is an Closing parenthesis, then do the following operations given below,
            else
            {

                // 1. If character "ch" is a Closing parenthesis, in the past, while traversing the infix expression,  we must have encountered an opening parenthesis.

                // 2. In between these pairs of parenthesis an operator must present. SO, keep popping from the stack and store/print till opening parenthesis is found.
                char Operator;
                while (!st.empty() && st.top() != '(')
                {
                    switch (st.top())
                    {
                    case '+':
                        Operator = '+';
                        break;
                    case '-':
                        Operator = '-';
                        break;
                    case '/':
                        Operator = '/';
                        break;
                    case '*':
                        Operator = '*';
                        break;
                    case '^':
                        Operator = '^';
                        break;
                    }

                    st.pop();
                }

                st.pop();
                postFixExpression.push_back(Operator);
            }
        }

        // After the above loops end, it may possible that the stack is not empty.
        // Now store all elements of the stack into our answer.
        while (!st.empty())
        {
            postFixExpression.push_back(st.top());
            st.pop();
        }
        
        // return answer.
        return postFixExpression;
    }
};

int main(void)
{
    string InfixExpression = "((a+(b*d))+e)"; // Postfix Expression => ab+cd/-.

    Solution S;
    cout << S.ConvertInfixExpressionToPostfixExpression(InfixExpression) << endl;
}