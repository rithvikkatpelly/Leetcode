class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)
        # dp[i] = number of ways to decode s[0:i]
        dp = [0] * (n + 1)
        dp[0] = 1  # empty string has exactly one way to decode (do nothing)
        dp[1] = 1 if s[0] != '0' else 0  # first character can't be '0' alone

        for i in range(2, n + 1):
            one_digit = s[i - 1]      # the single character just before position i
            two_digit = s[i - 2:i]    # the two characters just before position i

            if one_digit != '0':
                dp[i] += dp[i - 1]

            if '10' <= two_digit <= '26':
                dp[i] += dp[i - 2]

        return dp[n]    