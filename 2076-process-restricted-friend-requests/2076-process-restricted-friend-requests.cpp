#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, sz;
    DSU(int n): p(n), sz(n,1) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x){
        if(p[x]==x) return x;
        return p[x]=find(p[x]);
    }
    void unite(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return;
        if(sz[a]<sz[b]) swap(a,b);
        p[b]=a;
        sz[a]+=sz[b];
    }
};

class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions,
                                vector<vector<int>>& requests) {
        DSU dsu(n);
        vector<bool> ans;
        ans.reserve(requests.size());

        for (auto &req : requests) {
            int u = req[0], v = req[1];
            int ru = dsu.find(u), rv = dsu.find(v);

            if (ru == rv) { // already friends (directly or indirectly)
                ans.push_back(true);
                continue;
            }

            bool ok = true;
            // Check if merging ru and rv would violate any restriction
            for (auto &res : restrictions) {
                int x = res[0], y = res[1];
                int rx = dsu.find(x), ry = dsu.find(y);

                // If x is in ru and y is in rv (or vice versa), merge would connect them -> violation
                if ((rx == ru && ry == rv) || (rx == rv && ry == ru)) {
                    ok = false;
                    break;
                }
            }

            if (ok) dsu.unite(ru, rv);
            ans.push_back(ok);
        }
        return ans;
    }
};
