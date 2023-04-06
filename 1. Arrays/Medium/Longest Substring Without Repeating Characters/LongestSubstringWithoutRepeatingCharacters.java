import java.util.HashSet;

public class LongestSubstringWithoutRepeatingCharacters {

    /* Approach :- Using set */
    // Time Complexity :- O(n)
    // Space Complexity :- O(n)
    static int lengthOfLongestSubstring(String s) {
        // size of string.
        int len = s.length();

        // corner case
        if (len == 0) {
            return 0;
        }
        if (len == 1) {
            return 1;
        }

        // hashset
        HashSet<Integer> hashSet = new HashSet<>();

        // pointers.
        int left = 0, right = 0;

        // variable to store maxlength.
        int maxLen = 0;

        while(right < len)
        {

            // if s[right] is a unique element, then insert it into set.
            int element = s.charAt(right);
            if(hashSet.contains(element) == false)
            {
                hashSet.add(element);
            }
            else{
                // but if it is a duplicate element, the start removing element from set, untill you remove the duplicate of s[right].
                while(hashSet.contains(element) == true)
                {
                    int ch = s.charAt(left);
                    hashSet.remove(ch);
                    left++;
                }
                
                // after removing the duplicate of s[right], s[right]  become unique.
                // So, insert it into set.
                hashSet.add(element);
            }

            // update max length and incremeth the right pointer.
            maxLen = Math.max(maxLen, (right - left + 1));
            right++;
            
        }

        return maxLen;
    }

    public static void main(String[] args) {
        String str = "abcabcbb";

        System.out.println(lengthOfLongestSubstring(str));
    }
}
