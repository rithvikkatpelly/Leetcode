#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = (int)values.size();
        vector<vector<pair<int,int>>> g(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1], t = e[2];
            g[u].push_back({v, t});
            g[v].push_back({u, t});
        }

        vector<int> vis(n, 0);
        int ans = 0;

        function<void(int,int,long long)> dfs = [&](int u, int timeSpent, long long quality) {
            // if we're at 0, it's a valid path end (as long as timeSpent <= maxTime)
            if (u == 0) ans = max<long long>(ans, quality);

            for (auto [v, w] : g[u]) {
                int nt = timeSpent + w;
                if (nt > maxTime) continue;

                bool firstTime = (vis[v] == 0);
                vis[v]++;
                long long nq = quality + (firstTime ? values[v] : 0);

                dfs(v, nt, nq);

                vis[v]--;
            }
        };

        vis[0] = 1;
        dfs(0, 0, values[0]);   // include node 0 once

        return ans;
    }
};
