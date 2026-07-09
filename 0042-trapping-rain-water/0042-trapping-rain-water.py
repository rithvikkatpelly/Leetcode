class Solution:
    def trap(self, height):
        left, right = 0, len(height) - 1
        left_max = right_max = 0
        water = 0

        while left < right:
            if height[left] < height[right]:
                if height[left] >= left_max:
                    left_max = height[left]  # new left wall found
                else:
                    water += left_max - height[left]  # trap water
                left += 1
            else:
                if height[right] >= right_max:
                    right_max = height[right]  # new right wall found
                else:
                    water += right_max - height[right]  # trap water
                right -= 1

        return water 