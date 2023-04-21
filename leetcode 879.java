class Solution {
    public int profitableSchemes(int G, int P, int[] group, int[] profit) {
        int len = group.length;
        int mod = 1000000000 + 7;
        int[][] dp = new int[G + 1][P + 1];
        dp[0][0] = 1;
        for (int i = 1; i <= len; i++) {
            int p = profit[i - 1];
            int g = group[i - 1];
            for (int j = G; j >= 0; j--) {
                for (int k = P; k >= 0; k--) {
                    if (j >= g) {
                        dp[j][k] = (dp[j][k] + dp[j - g][Math.max(0, k - p)]) % mod;
                    }
                }
            }
        }
        int res = 0;
        for (int i = 0; i <= G; i++) {
            res = (res + dp[i][P]) % mod;
        }
        return res;
    }
}
