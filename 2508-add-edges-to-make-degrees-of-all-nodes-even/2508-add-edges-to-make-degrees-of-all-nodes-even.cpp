#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static long long enc(int u, int v) {
        if (u > v) swap(u, v);
        return ( (long long)u << 20 ) ^ v; // n <= 1e5 fits in 20 bits
    }

    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<int> deg(n + 1, 0);
        unordered_set<long long> has;
        has.reserve(edges.size() * 2);
        has.max_load_factor(0.7f);

        for (auto &e : edges) {
            int a = e[0], b = e[1];
            deg[a]++; deg[b]++;
            has.insert(enc(a, b));
        }

        vector<int> odd;
        for (int i = 1; i <= n; i++) {
            if (deg[i] & 1) odd.push_back(i);
        }

        if (odd.size() == 0) return true;

        if (odd.size() == 2) {
            int a = odd[0], b = odd[1];
            if (!has.count(enc(a, b))) return true;

            // need an intermediate node x
            for (int x = 1; x <= n; x++) {
                if (x == a || x == b) continue;
                if (!has.count(enc(a, x)) && !has.count(enc(b, x))) return true;
            }
            return false;
        }

        if (odd.size() == 4) {
            int a = odd[0], b = odd[1], c = odd[2], d = odd[3];
            auto ok = [&](int x1, int y1, int x2, int y2) {
                return !has.count(enc(x1, y1)) && !has.count(enc(x2, y2));
            };
            return ok(a,b,c,d) || ok(a,c,b,d) || ok(a,d,b,c);
        }

        return false;
    }
};
