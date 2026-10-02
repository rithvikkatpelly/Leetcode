class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        m, n = len(mat), len(mat[0])
        diags = [[] for _ in range(m + n - 1)]
        for i in range(m):
            for j in range(n):
                diags[i + j].append(mat[i][j])

        res = []
        for d, diag in enumerate(diags):
            if d % 2 == 0:
                res.extend(reversed(diag))
            else:
                res.extend(diag)
        return res