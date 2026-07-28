class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        word_set = set(wordDict)
        n = len(s)
        
        # dp[i] = True if s[:i] can be segmented into words from wordDict
        dp = [False] * (n + 1)
        dp[0] = True  # empty prefix is trivially segmentable
        
        for i in range(1, n + 1):
            for j in range(i):
                if dp[j] and s[j:i] in word_set:
                    dp[i] = True
                    break
        
        return dp[n]