class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        first = {0: -1}
        balance = best = 0
        for i, n in enumerate(nums):
            balance += 1 if n else -1
            if balance in first:
                best = max(best, i - first[balance])
            else:
                first[balance] = i
        return best    