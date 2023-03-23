class Solution(object):
    def makeConnected(self, n, connections):
        """
        :type n: int
        :type connections: List[List[int]]
        :rtype: int
        """
        if len(connections) < n - 1:
            return -1

        def union(x, y):
            p1, p2 = find(x), find(y)
            if p1 != p2:
                parents[p2] = p1
                self.cnt -= 1

        def find(x):
            if parents[x] != x:
                parents[x] = find(parents[x])
            return parents[x]

        parents = list(range(n))
        self.cnt = n
        for x, y in connections:
            union(x, y)
        return self.cnt - 1
