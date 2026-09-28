class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        row_count = Counter(tuple(row) for row in grid)
        res = 0
        for col in zip(*grid):
            res += row_count[col]
        return res    