class Solution(object):
    def combinationSum4(self, nums, target):

        dp = [0] * (target+1)
        dp[0] = 1 
        for i in range(1, target + 1):
            # update dp[i]
            for d in nums:
                if i >= d: dp[i] += dp[i-d]
                
        return dp[target]
