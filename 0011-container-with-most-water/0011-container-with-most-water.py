class Solution:
    def maxArea(self, height):
        left, right = 0, len(height) - 1
        max_water = 0

        while left < right:
            # Width is the distance between the two pointers
            width = right - left
            # Height is limited by the shorter line
            current_water = width * min(height[left], height[right])
            max_water = max(max_water, current_water)

            # Move the shorter line inward — only chance to find more water
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1

        return max_water