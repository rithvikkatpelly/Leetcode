#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();
        queue<pair<int,int>> q;

        auto push_if_O = [&](int r, int c) {
            if (r < 0 || r >= m || c < 0 || c >= n) return;
            if (board[r][c] == 'O') {
                board[r][c] = '#';          // mark as safe (border-connected)
                q.push({r, c});
            }
        };

        // 1) Start from all border cells
        for (int r = 0; r < m; r++) {
            push_if_O(r, 0);
            push_if_O(r, n - 1);
        }
        for (int c = 0; c < n; c++) {
            push_if_O(0, c);
            push_if_O(m - 1, c);
        }

        // 2) BFS to mark all O's connected to the border
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for (int k = 0; k < 4; k++) {
                push_if_O(r + dr[k], c + dc[k]);
            }
        }

        // 3) Flip captured regions, restore safe marks
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (board[r][c] == 'O') board[r][c] = 'X';   // captured
                else if (board[r][c] == '#') board[r][c] = 'O'; // restore
            }
        }
    }
};
