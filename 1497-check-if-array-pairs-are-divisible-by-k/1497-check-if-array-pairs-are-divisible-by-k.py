class Solution:
    def canArrange(self, arr: List[int], k: int) -> bool:
        count = [0] * k
        for x in arr:
            count[x % k] += 1

        if count[0] % 2:
            return False
        for r in range(1, k // 2 + 1):
            if r == k - r:
                if count[r] % 2:
                    return False
            elif count[r] != count[k - r]:
                return False
        return True    