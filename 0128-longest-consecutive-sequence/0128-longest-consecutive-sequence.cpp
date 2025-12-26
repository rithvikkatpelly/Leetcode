#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> st;
        st.reserve(nums.size() * 2);
        st.max_load_factor(0.7f);

        for (int x : nums) st.insert(x);

        int best = 0;

        // iterate over the set (unique values only)
        for (int x : st) {
            // only start counting if x is the start of a sequence
            if (st.find(x - 1) != st.end()) continue;

            int cur = x;
            int len = 1;
            while (st.find(cur + 1) != st.end()) {
                cur++;
                len++;
            }
            best = max(best, len);
        }

        return best;
    }
};
