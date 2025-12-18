#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> st; // stack of indices with increasing heights
        long long best = 0;

        // Add a sentinel 0-height bar to flush the stack at the end
        heights.push_back(0);

        for (int i = 0; i < (int)heights.size(); i++) {
            while (!st.empty() && heights[st.back()] > heights[i]) {
                int h = heights[st.back()];
                st.pop_back();

                int left = st.empty() ? 0 : st.back() + 1;
                int width = i - left;

                best = max(best, 1LL * h * width);
            }
            st.push_back(i);
        }

        heights.pop_back(); // restore input if you care

        return (int)best;
    }
};
