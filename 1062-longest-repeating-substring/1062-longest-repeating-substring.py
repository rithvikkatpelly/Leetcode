class Solution:
    def longestRepeatingSubstring(self, s):
        n = len(s)
        result = 0

        # Try all lengths from longest to shortest
        for length in range(n - 1, 0, -1):
            seen = set()
            for i in range(n - length + 1):
                sub = s[i:i + length]
                if sub in seen:
                    return length  # first match is the longest
                seen.add(sub)

        return 0
        