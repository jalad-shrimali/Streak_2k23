from collections import deque

class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        def appendNextIsland(x, y):
            if not (0 < x < X - 1 and 0 < y < Y - 1): self.is_closed = False
                
            for i, j in [(x + 1, y), (x, y + 1), (x - 1, y), (x, y - 1)]:
                    if not (0 <= i < X and 0 <= j < Y) or grid[i][j] == 1 or not available[i][j]: continue
                    stack.append([i, j])
                    available[i][j] = False
                    
        try:
            X, Y = len(grid), len(grid[0])
        except:
            return 0

        available = [[True for _ in range(Y)] for _ in range(X)]
        ret = 0
        stack = deque()

        for x in range(X):
            for y in range(Y):
                if not available[x][y]: continue
                available[x][y] = False
                if grid[x][y] == 1: continue

                self.is_closed = True
                stack.append([x, y])

                while stack:
                    i, j = stack.pop()
                    appendNextIsland(i, j)
                    
                if self.is_closed: ret += 1
        return ret
