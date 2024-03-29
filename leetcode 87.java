//Time limit exceeded
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

//Correct

public class Solution {
    public boolean isScramble(String s1, String s2) {
        if (s1.length() != s2.length()) {
            return false;
        }
        int len = s1.length();
        boolean [][][] state = new boolean[len][len][len+1];
        for (int l = 1; l <= len; l++) { // l is the length of strings
                                         // note that it is from 1 to len
            for (int i = 0; i + l <= len; i++) { // startingpoint for s1
                for (int j = 0; j + l <= len; j++) { // startingpoint for s2
                    if (l == 1) { // initialization
                        state[i][j][l] = s1.charAt(i) == s2.charAt(j);
                    } else {
                        for (int k = 1; k < l && !state[i][j][l]; k++) { // k is the length of s1's left child
                                                                         // note !state[i][j][l] here
                                                                         // stop this for loop when state[i][j][l] is true
                            // there are 2 cases
                            // 1. don't choose the current node to swap
                            // 2. choose the current node to swap
                            state[i][j][l] = (state[i][j][k] && state[i+k][j+k][l-k]) ||
                                             (state[i][j+l-k][k] && state[i+k][j][l-k]);
                        }
                    }
                }
            }
        }
        return state[0][0][len];
    }
}
