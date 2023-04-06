import java.util.ArrayList;

public class CommonElements {

    /*
     * Approach :-
     * 
     * Step 1:- Find the intersection of array A and array B and store it in a
     * seperate vector, let's called as temp.
     * Step 2:- Now, Find the intersection of temp array and array C and store it in
     * a seperate vector, let's called as ans.
     * Step 3:- Return ans vector.
     * 
     * Time Complexity :- O(n1 + n2 + n3)
     * Space Complexity :- O(n1 + n2 + n3), in case of all common elements, then
     * answer vector is of size n1+n2+n3.
     */
    static ArrayList<Integer> commonElements(int A[], int B[], int C[], int n1, int n2, int n3) {

        // array lits to store intersection of array A and B.
        ArrayList<Integer> intersection = new ArrayList<>();

        // array list to store intersection of array intersection and C.
        ArrayList<Integer> ans = new ArrayList<>();

        // variables to traverse array A and B.
        int i = 0, j = 0;

        while (i < n1 && j < n2) {
            if (A[i] == B[j]) {
                intersection.add(A[i]);

                // Skipping duplicates.
                while (i + 1 < n1 && A[i] == A[i + 1]) {
                    i++;
                }
                while (j + 1 < n2 && B[j] == B[j + 1]) {
                    j++;
                }

                i++;
                j++;
            }

            else if (A[i] < B[j]) {
                i++;
            } else {
                j++;
            }
        }

        // variables to traverse array intersection and C.
        i = 0;
        j = 0;
        while (i < intersection.size() && j < n3) {
            if (intersection.get(i) == C[j]) {
                ans.add(intersection.get(i));

                i++;
                j++;
            }

            else if (intersection.get(i) < C[j]) {
                i++;
            } else {
                j++;
            }
        }

        return ans;

    }

    public static void main(String[] args) {
        int A[] = { 1, 5, 10, 20, 40, 80 };
        int B[] = { 6, 7, 20, 80, 100 };
        int C[] = { 3, 4, 15, 20, 30, 70, 80, 120 };

        ArrayList<Integer> ans = new ArrayList<>();

        ans = commonElements(A, B, C, A.length, B.length, C.length);
        // printing answer.
        for (int x : ans) {
            System.out.print(x + " ");
        }
    }
}
