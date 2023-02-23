class Solution(object):
    def findMaximizedCapital(self, k, W, Profits, Capital):
        """
        :type k: int
        :type W: int
        :type Profits: List[int]
        :type Capital: List[int]
        :rtype: int
        """

        """ the TLE case is that k == len(capital), the following line can deal with and lead to AC
        if k == len(Capital):
            return W + sum(Profits)
        """
        for _ in xrange(k):
            idx = -1
            curr_max = 0
            for i in xrange(len(Capital)):
                if Capital[i] >= 0 and W >= Capital[i] and Profits[i] > curr_max:
                    curr_max = Profits[i]
                    idx = i
            if idx >= 0:
                W += curr_max
                Capital[idx] = -1
        return W
