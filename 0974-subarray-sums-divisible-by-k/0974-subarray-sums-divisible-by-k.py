class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        count = [0] * k
        count[0] = 1
        prefix = 0
        res = 0
        for x in nums:
            prefix = (prefix + x) % k
            res += count[prefix]
            count[prefix] += 1
        return res       