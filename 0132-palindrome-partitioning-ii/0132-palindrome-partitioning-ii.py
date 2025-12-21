class Solution(object):
    def minCut(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        if n <= 1:
            return 0

        # pal[i][j] = True if s[i:j+1] is a palindrome
        pal = [[False] * n for _ in range(n)]

        # Single characters
        for i in range(n):
            pal[i][i] = True

        # Length >= 2 substrings
        for length in range(2, n + 1):
            for i in range(n - length + 1):
                j = i + length - 1
                if s[i] == s[j]:
                    if length == 2:
                        pal[i][j] = True
                    else:
                        pal[i][j] = pal[i + 1][j - 1]

        # cuts[i] = min cuts for s[:i+1]
        cuts = [0] * n
        for i in range(n):
            if pal[0][i]:
                cuts[i] = 0
            else:
                # worst case: cut before every character
                min_cut = i
                for j in range(1, i + 1):
                    if pal[j][i]:
                        min_cut = min(min_cut, cuts[j - 1] + 1)
                cuts[i] = min_cut

        return cuts[n - 1]