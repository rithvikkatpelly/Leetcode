class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n, 0));
        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        int cur = 1;

        while (top <= bottom && left <= right) {
            // left -> right
            for (int j = left; j <= right; j++) mat[top][j] = cur++;
            top++;

            // top -> bottom
            for (int i = top; i <= bottom; i++) mat[i][right] = cur++;
            right--;

            // right -> left
            if (top <= bottom) {
                for (int j = right; j >= left; j--) mat[bottom][j] = cur++;
                bottom--;
            }

            // bottom -> top
            if (left <= right) {
                for (int i = bottom; i >= top; i--) mat[i][left] = cur++;
                left++;
            }
        }

        return mat;
    }
};
