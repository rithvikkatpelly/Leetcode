class Solution(object):
    def minDeletionSize(self, strs):
        """
        :type strs: List[str]
        :rtype: int
        """
        n = len(strs)          # number of rows
        m = len(strs[0])       # number of columns

        # dp[i] = longest valid subsequence of columns ending at i
        dp = [1] * m

        for i in range(m):
            for j in range(i):
                # check if we can place column i after column j
                ok = True
                for r in range(n):
                    if strs[r][j] > strs[r][i]:
                        ok = False
                        break
                if ok:
                    dp[i] = max(dp[i], dp[j] + 1)

        longest_keep = max(dp)
        return m - longest_keep