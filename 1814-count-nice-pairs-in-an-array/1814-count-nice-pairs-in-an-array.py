class Solution:
    def countNicePairs(self, nums: List[int]) -> int:
        MOD = 10**9 + 7
        count = {}
        res = 0
        for x in nums:
            key = x - int(str(x)[::-1])
            c = count.get(key, 0)
            res += c
            count[key] = c + 1
        return res % MOD