#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        vector<bool> col(n, false);
        vector<bool> diag1(2 * n - 1, false); // r - c + (n-1)
        vector<bool> diag2(2 * n - 1, false); // r + c

        function<void(int)> backtrack = [&](int r) {
            if (r == n) {
                ans.push_back(board);
                return;
            }
            for (int c = 0; c < n; c++) {
                int d1 = r - c + (n - 1);
                int d2 = r + c;
                if (col[c] || diag1[d1] || diag2[d2]) continue;

                board[r][c] = 'Q';
                col[c] = diag1[d1] = diag2[d2] = true;

                backtrack(r + 1);

                board[r][c] = '.';
                col[c] = diag1[d1] = diag2[d2] = false;
            }
        };

        backtrack(0);
        return ans;
    }
};
