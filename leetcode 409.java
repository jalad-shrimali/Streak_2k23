class Solution {
public int longestPalindrome(String s) {
    int n = 'z' - 'A' + 1;
    int[] count = new int[n];
    char[] arr = s.toCharArray();
    for (char c : arr) {
        count[c - 'A']++;
    }
    int res = 0;
    int oddCount = 0;
    for (int i : count) {
        if (i % 2 != 0) oddCount++;
        res += i;
    }
    res -= oddCount > 1 ? oddCount - 1 : 0;
    return res;
}
}
