class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        S= len(spells)
        P= len(potions)

        potions.sort()
        ans= [None]* S

        for i,s in enumerate(spells):
            ans[i]= P-bisect.bisect_left(potions, success/s)

        return ans
