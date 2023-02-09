class Solution:
    def distinctNames(self, ideas: List[str]) -> int:
        ans = 0
        seen = set(ideas)
        starts = collections.defaultdict(set)

        for idea in ideas:
            starts[idea[0]].add(idea[1:])
        for j in range(25):
            for i in range(j + 1, 26):
                set_x = starts[chr(i + 97)]
                set_y = starts[chr(j + 97)]
                intersections = len(set_x & set_y) 
                ans += 2 * (len(set_x) - intersections) * (len(set_y) - intersections)
        return ans
