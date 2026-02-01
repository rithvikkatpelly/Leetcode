#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
    int largestRectangleArea(vector<int>& h) {
        stack<int> st;                 // indices, increasing heights
        int best = 0;
        int n = (int)h.size();

        for (int i = 0; i <= n; i++) {
            int cur = (i == n ? 0 : h[i]); // sentinel 0 to flush stack
            while (!st.empty() && cur < h[st.top()]) {
                int height = h[st.top()];
                st.pop();
                int left = st.empty() ? -1 : st.top();
                int width = i - left - 1;
                best = max(best, height * width);
            }
            st.push(i);
        }
        return best;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int R = (int)matrix.size();
        int C = (int)matrix[0].size();

        vector<int> heights(C, 0);
        int ans = 0;

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (matrix[r][c] == '1') heights[c] += 1;
                else heights[c] = 0;
            }
            ans = max(ans, largestRectangleArea(heights));
        }
        return ans;
    }
};
