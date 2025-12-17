#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;
        for (int x : nums) {
            total += x;
        }

        int rem = total % p;
        if (rem == 0) return 0;  // already divisible, remove nothing

        unordered_map<int, int> lastIndex;
        lastIndex[0] = -1;       // prefix sum before array starts
        long long prefix = 0;
        int n = (int)nums.size();
        int ans = n;             // we will minimize this

        for (int i = 0; i < n; ++i) {
            prefix = (prefix + nums[i]) % p;
            int want = (int)((prefix - rem + p) % p);
            
            if (lastIndex.count(want)) {
                ans = min(ans, i - lastIndex[want]);
            }
            
            // store/update current prefix index
            lastIndex[(int)prefix] = i;
        }

        return ans == n ? -1 : ans;
    }
};
