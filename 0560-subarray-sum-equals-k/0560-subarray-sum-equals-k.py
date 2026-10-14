class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        count = 0
        prefix = 0
        seen = {0: 1}  # empty prefix, so subarrays starting at index 0 count
        for num in nums:
            prefix += num
            count += seen.get(prefix - k, 0)
            seen[prefix] = seen.get(prefix, 0) + 1
        return count
