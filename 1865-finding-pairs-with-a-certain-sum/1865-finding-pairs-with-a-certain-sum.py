from collections import Counter
from typing import List

class FindSumPairs:

    def __init__(self, nums1: List[int], nums2: List[int]):
        self.nums2 = nums2
        self.cnt1 = Counter(nums1)
        self.cnt2 = Counter(nums2)

    def add(self, index: int, val: int) -> None:
        old = self.nums2[index]
        self.cnt2[old] -= 1
        self.nums2[index] = old + val
        self.cnt2[old + val] += 1

    def count(self, tot: int) -> int:
        cnt2 = self.cnt2
        return sum(c * cnt2.get(tot - x, 0) for x, c in self.cnt1.items())


# Your FindSumPairs object will be instantiated and called as such:
# obj = FindSumPairs(nums1, nums2)
# obj.add(index,val)
# param_2 = obj.count(tot)