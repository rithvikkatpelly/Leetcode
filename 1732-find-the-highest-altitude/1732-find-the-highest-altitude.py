from typing import List

class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        alt = best = 0
        for g in gain:
            alt += g
            best = max(best, alt)
        return best