class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        best = cur = 0
        for n in nums:
            cur = cur + 1 if n else 0
            best = max(best, cur)
        return best 