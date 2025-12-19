#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = (int)nums1.size(), n2 = (int)nums2.size();
        vector<vector<int>> ans;
        if (n1 == 0 || n2 == 0 || k == 0) return ans;

        using Node = pair<long long, pair<int,int>>; 
        // {sum, {i, j}}

        priority_queue<Node, vector<Node>, greater<Node>> pq;

        // seed: (i, 0) for first min(k, n1) rows
        int limit = min(k, n1);
        for (int i = 0; i < limit; i++) {
            pq.push({(long long)nums1[i] + nums2[0], {i, 0}});
        }

        while (!pq.empty() && (int)ans.size() < k) {
            auto [sum, ij] = pq.top(); pq.pop();
            int i = ij.first, j = ij.second;

            ans.push_back({nums1[i], nums2[j]});

            if (j + 1 < n2) {
                pq.push({(long long)nums1[i] + nums2[j + 1], {i, j + 1}});
            }
        }

        return ans;
    }
};
