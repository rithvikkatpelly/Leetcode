class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        count = {}
        res = 0
        for j, x in enumerate(nums):
            key = x - j
            res += j - count.get(key, 0)
            count[key] = count.get(key, 0) + 1
        return res
        