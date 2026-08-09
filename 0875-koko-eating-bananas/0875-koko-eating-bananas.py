import math
from typing import List

class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        left, right = 1, max(piles)
        
        def hours_needed(k: int) -> int:
            return sum(math.ceil(pile / k) for pile in piles)
        
        while left < right:
            mid = (left + right) // 2
            if hours_needed(mid) <= h:
                right = mid
            else:
                left = mid + 1
        
        return left