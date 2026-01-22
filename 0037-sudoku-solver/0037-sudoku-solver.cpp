#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int row[9] = {0}, col[9] = {0}, box[9] = {0};
        vector<pair<int,int>> empties;

        auto boxId = [&](int r, int c) { return (r / 3) * 3 + (c / 3); };

        // init masks + list empty cells
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') {
                    empties.push_back({r, c});
                } else {
                    int d = board[r][c] - '1';      // 0..8
                    int bit = 1 << d;
                    row[r] |= bit;
                    col[c] |= bit;
                    box[boxId(r,c)] |= bit;
                }
            }
        }

        function<bool(int)> dfs = [&](int idx) -> bool {
            if (idx == (int)empties.size()) return true;

            // choose current empty cell
            auto [r, c] = empties[idx];
            int b = boxId(r, c);

            int used = row[r] | col[c] | box[b];
            int avail = (~used) & ((1 << 9) - 1); // bits for digits we can place

            while (avail) {
                int bit = avail & -avail;        // lowest set bit
                avail -= bit;

                int d = __builtin_ctz(bit);      // digit index 0..8
                board[r][c] = char('1' + d);

                row[r] |= bit; col[c] |= bit; box[b] |= bit;
                if (dfs(idx + 1)) return true;
                row[r] ^= bit; col[c] ^= bit; box[b] ^= bit;

                board[r][c] = '.';
            }
            return false;
        };

        dfs(0);
    }
};
