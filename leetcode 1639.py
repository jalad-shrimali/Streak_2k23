class Solution(object):
    def numWays(self, words, target):
        """
        :type words: List[str]
        :type target: str
        :rtype: int
        """
        MOD = 10**9+7
        dp = [0]*(len(target)+1)
        dp[0] = 1
        for i in xrange(len(words[0])):
            count = collections.Counter(w[i] for w in words)
            for j in reversed(xrange(len(target))):
                dp[j+1] += dp[j]*count[target[j]] % MOD
        return dp[-1] % MOD
