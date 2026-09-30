class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        count = [0] * 60
        res = 0
        for t in time:
            r = t % 60
            res += count[(60 - r) % 60]
            count[r] += 1
        return res    