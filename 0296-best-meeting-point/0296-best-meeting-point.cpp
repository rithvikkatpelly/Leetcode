class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> rows, cols;
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    rows.push_back(i);
                }
            }
        }
        
        // Collect cols (sorted)
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                if (grid[i][j] == 1) {
                    cols.push_back(j);
                }
            }
        }

        // Get median row and col
        int median_row = rows[rows.size() / 2];
        int median_col = cols[cols.size() / 2];

        // Sum distances
        int distance = 0;
        for (int r : rows) {
            distance += abs(r - median_row);
        }
        for (int c : cols) {
            distance += abs(c - median_col);
        }
        return distance;
    }
};
