class Solution {

    public String longestPalindrome(String s) {
        String result = "";
        int resLength = 0;
        if (s.length() == 0) return result;

        for (int i = 0; i < s.length(); i++) {
            int left = i, right = i;
            // we treat each element of string as the center and expand outwards.
            while (
                left >= 0 &&
                right < s.length() &&
                s.charAt(left) == s.charAt(right)
            ) {
                if ((right - left + 1) > resLength) { // if distance b/w left and right is > resLength
                    resLength = right - left + 1;
                    result = s.substring(left, right + 1); // the matched index from left to resLength
                }
                left--;
                right++;
            }

            //  Even Length Palindromes
            left = i;
            right = i + 1;
            while (
                left >= 0 &&
                right < s.length() &&
                s.charAt(left) == s.charAt(right)
            ) {
                if ((right - left + 1) > resLength) {
                    resLength = right - left + 1;
                    result = s.substring(left, right + 1);
                }
                left--;
                right++;
            }
        }
        return result;
    }
}

public class longestPalindromeLC {

    public static void main(String[] args) {
        String s = "abababc";

        Solution sol = new Solution();
        System.out.println("Longest Palindrome is " + sol.longestPalindrome(s));
    }
}
