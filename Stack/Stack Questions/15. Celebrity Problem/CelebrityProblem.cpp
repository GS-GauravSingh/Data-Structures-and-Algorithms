/*
Question in short:- Everyon knows celebrity but celebrity does not know anyone. If you go to a party of N people, find if there is a celebrity or not.

Given a square matrix of 0 and 1 called as M of size N, representing the people at the party, if M[i][j] = 1 means ith person knows jth personn else M[i][j] = 0.

Ex:-M =  {
    Row index(below)      0 1 2  <== Column index
                    0    {0,1,0},
                    1    {0,0,0},
                    2    {0,1,0}

    }

    M[i][j] = 1, means ith person knows jth person.
    ex:- Row = 0, col = 1, means M[0][1] = 1, means 0th person knows 1th person.

    M[i][j] = 0, means ith person does not know jth person.
    ex:- Row = 0, col = 2, means M[0][2] = 0, means 0th person does not knows 2th person.

    Note:- ignore the diagonal elements. The reason is, in case of diagonal elements i == j, means we are talking about same person and it's obvious that a person know itself.

    So, answer of above examples is 1 (Row). Means 1 is a celebrity.

    Because 1 does not know anyone and eyeryone knows 1{ M[0][1] = 1, M[2][1] = 1 }.
*/

#include <bits/stdc++.h>
using namespace std;

/* ------------------- Solution Class ------------------------ */
class Solution
{
private:
public:
    /* Brute Force Approach :-

        if(isCelebrity(i) == true)
        {
            // ith row will contains all 0's and ith column will have all 1's,
            // except for the diagonal element.
        }
    */
    // Time Complexity :- O(n^2), n is the size of matrix.
    // Space Complexity :- O(1)
    int celebrityProblem_BruteForce(vector<vector<int>> &M, int n)
    {
        // flag to check if we found the celebrity or not.
        bool isCelebrity = false;

        // Step 1:- First, we need to find the row in which all elements have the value 0.
        for (int row = 0; row < n; row++)
        {
            // flag to check, if we found the row that contains all 0's or not.
            bool rowFound = false;

            for (int col = 0; col < n; col++)
            {
                if (M[row][col] == 0)
                {
                    rowFound = true;
                }
                else
                {
                    // if we found a non-zero value in this particular row, then break this loop
                    // there is no need to check rest of the element of this row.
                    // simply move to next row.
                    rowFound = false;
                    break;
                }
            }

            // if rowFound == true, means we found the row in which all elements have the value 0.
            // Step 2 :- after finding the ith row that contains all 0's. Now silmply check, if the ith column contains all 1's or not.
            if (rowFound == true)
            {
                // iterating through the column of that row which contains all 0's.
                for (int i = 0; i < n; i++)
                {
                    // skip the diagonal element.
                    if (i == row)
                    {
                        continue;
                    }
                    else if (M[i][row] == 1)
                    {
                        isCelebrity = true;
                    }
                    else
                    {
                        isCelebrity = false;
                        break;
                    }
                }
            }

            // if we found the row which contains all 0's and column of that row contains all 1's except diagonal element, that row is ore celevrity.
            if (isCelebrity == true)
            {
                return row;
            }
        }

        return -1;
    }

    /*

    Optimized Approach :- Using Stack.

    Steps:-
    1. First, insert all N peoples into stack.
    2. Till the size of the stack is not 1, take out 2 elements/peoples from the stack and do the following operation,

    // taking out 2 elements.
    A = st.top();    // 1st element/people.
    st.pop();        // popping the 1st element/people.
    B = st.top();    // 2nd element/people.
    st.pop();        // popping the 2nd element/people.

    Now, we have 2 cases,
    // 1st case,
    if(A knows B){
        if A knows B, it means A is not a celebrity, because a celebrity is a person who does not know anyone. So, Discard A and push B into stack.
    }

    // 2nd case,
    if(B knows A){
        if B knows A, it means B is not a celebrity, because a celebrity is a person who does not know anyone. So, Discard B and push A into stack.
    }

    After performing the above operations, our stack is left with a single element and that element may be a celebrity. So, you need to verify it by checking its row and column.

    If it is a celebrity then, its row must contain all 0s, and the column must contain all 1's except for the diagonal element.
    */
    // Time complexity :- O(n)
    // Space complexity :- O(n)

    /* Method that return true if person A know person B otherwise return false. */
    bool knows(vector<vector<int>> &M, int personA, int personB)
    {
        // if M[i][j] == 1, it means ith person knows jth person.
        // if M[i][j] == 0, it means ith person does not know jth person.
        return M[personA][personB];
    }

    int celebrityProblem_Optimized(vector<vector<int>> &M, int n)
    {

        // Step 1 :- Insert all N peoples into stack.
        stack<int> st;
        for (int people = 0; people < n; people++)
        {
            st.push(people);
        }

        // Step 2 :- take out 2 peoples from stack and compare them, till the size of stack is not 1.
        while (st.size() > 1)
        {
            int A = st.top(); // taking out 1st person.
            st.pop();         // pop it.

            int B = st.top(); // taking out 2nd person.
            st.pop();         // pop it.

            // compare them.
            /*
                if(A knows B){
                    if A knows B, it means A is not a celebrity, because a celebrity is a person who does not know anyone. So, Discard A and push B into stack.
                }
            */
            if (knows(M, A, B))
            {
                st.push(B);
            }
            else
            {
                /*
                if(B knows A){
                    if B knows A, it means B is not a celebrity, because a celebrity is a person who does not know anyone. So, Discard B and push A into stack.
                }
                */
                st.push(A);
            }
        }

        /*
        After performing the above operations, our stack is left with a single element and that element may be a celebrity. So, you need to verify it by checking its row and column.

        If it is a celebrity then, its row must contain all 0s, and the column must contain all 1's except for the diagonal element.
        */
        int possibleCandidate = st.top();

        // Step 3:- Verify this possibleCandidate. If it is a celebrity or not.

        // checking its row.
        bool rowCheck = true;
        for (int row = 0; row < n; row++)
        {
            if (M[possibleCandidate][row] != 0)
            {
                rowCheck = false;
                break;
            }
        }

        // checking its column.
        bool colCheck = true;
        for (int col = 0; col < n; col++)
        {
            // skipping diagonal element.
            if (possibleCandidate == col)
            {
                continue;
            }

            if (M[col][possibleCandidate] != 1)
            {
                colCheck = false;
                break;
            }
        }

        // if row contains all 0s and column contain all 1's except for diafonal element.
        // Then possibleCandidtae is a celebrity.
        if (rowCheck && colCheck)
        {
            return possibleCandidate;
        }
        return -1;
    }
};

int main(void)
{
    vector<vector<int>> M = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0},
    };

    int N = M.size();

    // Solution.
    Solution S;
    cout << "Celebrity : " << S.celebrityProblem_BruteForce(M, N) << endl;
    cout << "Celebrity : " << S.celebrityProblem_Optimized(M, N);
}
