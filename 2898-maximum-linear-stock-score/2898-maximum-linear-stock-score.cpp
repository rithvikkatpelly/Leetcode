#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& prices) {
        unordered_map<long long, long long> mp;
        long long ans = 0;

        for (int i = 0; i < prices.size(); i++) {
            long long key = 1LL * prices[i] - (i + 1); // 1-indexed
            mp[key] += prices[i];
            ans = max(ans, mp[key]);
        }

        return ans;
    }
};