#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = (int)points.size();
        vector<int> minDist(n, INT_MAX);
        vector<bool> inMST(n, false);

        minDist[0] = 0;
        long long total = 0;

        for (int it = 0; it < n; it++) {
            int u = -1;

            // pick the closest not-yet-in-MST node
            for (int i = 0; i < n; i++) {
                if (!inMST[i] && (u == -1 || minDist[i] < minDist[u])) {
                    u = i;
                }
            }

            inMST[u] = true;
            total += minDist[u];

            // relax edges from u to all other nodes
            for (int v = 0; v < n; v++) {
                if (!inMST[v]) {
                    int dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    minDist[v] = min(minDist[v], dist);
                }
            }
        }

        return (int)total;
    }
};
