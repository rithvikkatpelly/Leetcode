class Solution:
    def shuffle(self, nums, n):
        result = []

        for i in range(n):
            result.append(nums[i])      # xi from first half
            result.append(nums[i + n])  # yi from second half

        return result