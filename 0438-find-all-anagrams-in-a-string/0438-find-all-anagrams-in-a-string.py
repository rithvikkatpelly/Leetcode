class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        if len(p) > len(s):
            return []
        need = [0] * 26
        window = [0] * 26
        for ch in p:
            need[ord(ch) - 97] += 1

        res = []
        m = len(p)
        for i, ch in enumerate(s):
            window[ord(ch) - 97] += 1
            if i >= m:
                window[ord(s[i - m]) - 97] -= 1
            if window == need:
                res.append(i - m + 1)
        return res    