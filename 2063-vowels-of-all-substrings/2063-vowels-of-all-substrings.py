class Solution:
    def countVowels(self, word: str) -> int:
        n = len(word)
        vowels = set("aeiou")
        total = 0
        for i, ch in enumerate(word):
            if ch in vowels:
                total += (i + 1) * (n - i)
        return total   