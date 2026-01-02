#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) return true;

        vector<vector<int>> g(n);
        g.reserve(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<char> vis(n, 0);
        queue<int> q;
        q.push(source);
        vis[source] = 1;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : g[u]) {
                if (vis[v]) continue;
                if (v == destination) return true;
                vis[v] = 1;
                q.push(v);
            }
        }
        return false;
    }
};
