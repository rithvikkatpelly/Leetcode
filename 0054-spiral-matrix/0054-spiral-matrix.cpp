#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;

        vector<int> res;
        res.reserve(m * n);

        while (top <= bottom && left <= right) {
            // top row
            for (int c = left; c <= right; c++)
                res.push_back(matrix[top][c]);
            top++;

            // right column
            for (int r = top; r <= bottom; r++)
                res.push_back(matrix[r][right]);
            right--;

            // bottom row
            if (top <= bottom) {
                for (int c = right; c >= left; c--)
                    res.push_back(matrix[bottom][c]);
                bottom--;
            }

            // left column
            if (left <= right) {
                for (int r = bottom; r >= top; r--)
                    res.push_back(matrix[r][left]);
                left++;
            }
        }

        return res;
    }
};
