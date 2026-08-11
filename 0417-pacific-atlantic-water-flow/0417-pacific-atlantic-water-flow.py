from typing import List

class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        if not heights or not heights[0]:
            return []

        rows, cols = len(heights), len(heights[0])

        pacific_reachable = set()
        atlantic_reachable = set()

        def dfs(r, c, visited, prev_height):
            if (
                r < 0 or r >= rows or
                c < 0 or c >= cols or
                (r, c) in visited or
                heights[r][c] < prev_height
            ):
                return
            visited.add((r, c))
            dfs(r + 1, c, visited, heights[r][c])
            dfs(r - 1, c, visited, heights[r][c])
            dfs(r, c + 1, visited, heights[r][c])
            dfs(r, c - 1, visited, heights[r][c])

        # Start DFS from all cells bordering the Pacific (top row and left column)
        for c in range(cols):
            dfs(0, c, pacific_reachable, heights[0][c])
        for r in range(rows):
            dfs(r, 0, pacific_reachable, heights[r][0])

        # Start DFS from all cells bordering the Atlantic (bottom row and right column)
        for c in range(cols):
            dfs(rows - 1, c, atlantic_reachable, heights[rows - 1][c])
        for r in range(rows):
            dfs(r, cols - 1, atlantic_reachable, heights[r][cols - 1])

        # Cells reachable from both oceans
        return [list(cell) for cell in pacific_reachable & atlantic_reachable]    