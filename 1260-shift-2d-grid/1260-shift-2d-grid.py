class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        total = m * n
        k %= total
        flat = [v for row in grid for v in row]
        flat = flat[-k:] + flat[:-k] if k else flat
        return [flat[i * n:(i + 1) * n] for i in range(m)]    