class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int n = grid.size();

        // vis[r][c][dir]
        // dir = 0 -> horizontal: occupies (r,c), (r,c+1)
        // dir = 1 -> vertical:   occupies (r,c), (r+1,c)
        vector<vector<vector<int>>> vis(n, vector<vector<int>>(n, vector<int>(2, 0)));

        queue<tuple<int,int,int,int>> q;
        q.push({0, 0, 0, 0}); // r, c, dir, steps
        vis[0][0][0] = 1;

        while (!q.empty()) {
            auto [r, c, dir, steps] = q.front();
            q.pop();

            if (r == n - 1 && c == n - 2 && dir == 0) return steps;

            if (dir == 0) { 
                // horizontal: (r,c), (r,c+1)

                // move right
                if (c + 2 < n && grid[r][c + 2] == 0 && !vis[r][c + 1][0]) {
                    vis[r][c + 1][0] = 1;
                    q.push({r, c + 1, 0, steps + 1});
                }

                // move down
                if (r + 1 < n && grid[r + 1][c] == 0 && grid[r + 1][c + 1] == 0 && !vis[r + 1][c][0]) {
                    vis[r + 1][c][0] = 1;
                    q.push({r + 1, c, 0, steps + 1});
                }

                // rotate clockwise
                if (r + 1 < n && grid[r + 1][c] == 0 && grid[r + 1][c + 1] == 0 && !vis[r][c][1]) {
                    vis[r][c][1] = 1;
                    q.push({r, c, 1, steps + 1});
                }

            } else {
                // vertical: (r,c), (r+1,c)

                // move down
                if (r + 2 < n && grid[r + 2][c] == 0 && !vis[r + 1][c][1]) {
                    vis[r + 1][c][1] = 1;
                    q.push({r + 1, c, 1, steps + 1});
                }

                // move right
                if (c + 1 < n && grid[r][c + 1] == 0 && grid[r + 1][c + 1] == 0 && !vis[r][c + 1][1]) {
                    vis[r][c + 1][1] = 1;
                    q.push({r, c + 1, 1, steps + 1});
                }

                // rotate counterclockwise
                if (c + 1 < n && grid[r][c + 1] == 0 && grid[r + 1][c + 1] == 0 && !vis[r][c][0]) {
                    vis[r][c][0] = 1;
                    q.push({r, c, 0, steps + 1});
                }
            }
        }

        return -1;
    }
};