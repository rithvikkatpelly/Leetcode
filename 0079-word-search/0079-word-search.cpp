#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int m, n;
    string w;
    vector<vector<char>>* b;

    bool dfs(int r, int c, int idx) {
        if (idx == (int)w.size()) return true;               // matched all
        if (r < 0 || r >= m || c < 0 || c >= n) return false;
        if ((*b)[r][c] != w[idx]) return false;

        char saved = (*b)[r][c];
        (*b)[r][c] = '#';                                   // mark visited

        bool found = dfs(r + 1, c, idx + 1) ||
                     dfs(r - 1, c, idx + 1) ||
                     dfs(r, c + 1, idx + 1) ||
                     dfs(r, c - 1, idx + 1);

        (*b)[r][c] = saved;                                 // restore
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        b = &board;
        w = word;
        m = (int)board.size();
        n = (int)board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(i, j, 0)) return true;
            }
        }
        return false;
    }
};
