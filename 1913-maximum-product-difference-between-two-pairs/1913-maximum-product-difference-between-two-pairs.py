class Solution:
    def maxProductDifference(self, nums: List[int]) -> int:
        big1 = big2 = 0
        small1 = small2 = float('inf')
        for n in nums:
            if n > big1:
                big1, big2 = n, big1
            elif n > big2:
                big2 = n
            if n < small1:
                small1, small2 = n, small1
            elif n < small2:
                small2 = n
        return big1 * big2 - small1 * small2