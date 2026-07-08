class Solution:
    def moveZeroes(self, nums):
        insert = 0

        # Move all non-zero elements to the front
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[insert] = nums[i]
                insert += 1

        # Fill remaining positions with zeros
        while insert < len(nums):
            nums[insert] = 0
            insert += 1