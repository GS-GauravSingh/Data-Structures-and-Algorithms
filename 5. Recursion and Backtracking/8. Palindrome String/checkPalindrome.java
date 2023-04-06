
public class checkPalindrome {
    /* Approach 1 :- Using 2 pointer approach. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(1)
    static boolean checkPalindrome_Iteartive(String str) {
        int start = 0;
        int end = str.length() - 1;

        while (start <= end) {
            if (str.charAt(start) != str.charAt(end)) {
                return false;
            }

            start++;
            end--;
        }
        return true;
    }

    /* Approach 1 recursive code. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(n), recursive stack space.
    static boolean checkPalindrome_Recursive(String str, int start, int end) {
        // Base Condition.
        if (start >= end) {
            return true;
        }
        if (str.charAt(start) != str.charAt(end)) {
            return false;
        }

        // Recursive Case.
        return checkPalindrome_Recursive(str, start + 1, end - 1);
    }

    public static void main(String[] args) {
        String str = "RADAR";

        System.out.println(checkPalindrome_Iteartive(str));
        System.out.println(checkPalindrome_Recursive(str, 0, str.length() - 1));
    }
}
