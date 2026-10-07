class NeighborSum:

    def __init__(self, grid: List[List[int]]):
        n = len(grid)
        self.adj = [0] * (n * n)
        self.diag = [0] * (n * n)
        adj_dirs = ((-1, 0), (1, 0), (0, -1), (0, 1))
        diag_dirs = ((-1, -1), (-1, 1), (1, -1), (1, 1))
        for i in range(n):
            for j in range(n):
                v = grid[i][j]
                for di, dj in adj_dirs:
                    x, y = i + di, j + dj
                    if 0 <= x < n and 0 <= y < n:
                        self.adj[v] += grid[x][y]
                for di, dj in diag_dirs:
                    x, y = i + di, j + dj
                    if 0 <= x < n and 0 <= y < n:
                        self.diag[v] += grid[x][y]

    def adjacentSum(self, value: int) -> int:
        return self.adj[value]

    def diagonalSum(self, value: int) -> int:
        return self.diag[value]


# Your NeighborSum object will be instantiated and called as such:
# obj = NeighborSum(grid)
# param_1 = obj.adjacentSum(value)
# param_2 = obj.diagonalSum(value)