import math

class Solution(object):
    def minEatingSpeed(self, piles, h):
        def hours_needed(speed):
            return sum(math.ceil(float(pile) / speed) for pile in piles)

        lo, hi = 1, max(piles)
        while lo < hi:
            mid = (lo + hi) // 2
            if hours_needed(mid) <= h:
                hi = mid
            else:
                lo = mid + 1
        return lo