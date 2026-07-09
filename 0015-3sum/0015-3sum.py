class Solution:
    def threeSum(self, nums):
        nums.sort()
        result = []
        n = len(nums)

        for i in range(n - 2):
            # Early exit: if smallest number > 0, no triplet can sum to 0
            if nums[i] > 0:
                break

            # Skip duplicate values for the first number
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            left, right = i + 1, n - 1

            while left < right:
                total = nums[i] + nums[left] + nums[right]

                if total == 0:
                    result.append([nums[i], nums[left], nums[right]])

                    # Skip duplicates for second number
                    while left < right and nums[left] == nums[left + 1]:
                        left += 1
                    # Skip duplicates for third number
                    while left < right and nums[right] == nums[right - 1]:
                        right -= 1

                    left += 1
                    right -= 1

                elif total < 0:
                    left += 1   # need larger sum
                else:
                    right -= 1  # need smaller sum

        return result