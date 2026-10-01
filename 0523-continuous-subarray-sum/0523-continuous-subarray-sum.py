class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        first = {0: -1}
        prefix = 0
        for i, x in enumerate(nums):
            prefix = (prefix + x) % k
            if prefix in first:
                if i - first[prefix] >= 2:
                    return True
            else:
                first[prefix] = i
        return False     