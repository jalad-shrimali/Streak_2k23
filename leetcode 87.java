public class Solution {
    public boolean isScramble(String s1, String s2) {
        if (s1.equals(s2)) {
            return true;
        }
        int[] letters = new int[26];
        for (int i = 0; i < s1.length(); i++) {
            letters[s1.charAt(i)-'a']++;
            letters[s2.charAt(i)-'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (letters[i] != 0) {
                return false;
            }
        }
        for (int i = 1; i < s1.length(); i++) { // i is the length of s1's left child
            // there are 2 cases
            if (isScramble(s1.substring(0, i), s2.substring(0, i))
                && isScramble(s1.substring(i), s2.substring(i))) { // don't choose the current node to swap
                return true;
            }
            if (isScramble(s1.substring(0, i), s2.substring(s2.length()-i))
                && isScramble(s1.substring(i), s2.substring(0, s2.length()-i))) { // choose the current node to swap
                return true;
            }
        }
        return false;
    }
}
