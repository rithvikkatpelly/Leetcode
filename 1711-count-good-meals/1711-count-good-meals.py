class Solution:
    def countPairs(self, deliciousness: List[int]) -> int:
        MOD = 10**9 + 7
        count = {}
        res = 0
        for x in deliciousness:
            for p in range(22):
                res += count.get((1 << p) - x, 0)
            count[x] = count.get(x, 0) + 1
        return res % MOD 