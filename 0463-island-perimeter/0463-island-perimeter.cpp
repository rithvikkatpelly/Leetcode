#include <vector>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        int peri = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    peri += 4;
                    if (i > 0 && grid[i-1][j] == 1) peri -= 2; // shared with top
                    if (j > 0 && grid[i][j-1] == 1) peri -= 2; // shared with left
                }
            }
        }
        return peri;
    }
};
