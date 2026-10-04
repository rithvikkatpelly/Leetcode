class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        count = {0: 1}
        odds = result = 0
        for n in nums:
            odds += n & 1
            result += count.get(odds - k, 0)
            count[odds] = count.get(odds, 0) + 1
        return result   