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
#---------------------------------
import Queue
class Solution(object):
    def findMaximizedCapital(self, k, W, Profits, Capital):
        pq1 = Queue.PriorityQueue()
        pq2 = Queue.PriorityQueue()
        for i in xrange(len(Profits)):
            pq1.put((Capital[i], Profits[i]))
        
        for _ in xrange(k):
            while not pq1.empty() and pq1.queue[0][0] <= W:
                tmp = pq1.get()
                pq2.put((-tmp[1], tmp[1]))
            if not pq2.empty():
                W += pq2.get()[1]
        return W
