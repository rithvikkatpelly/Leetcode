#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, sz;
    DSU(int n) : p(n), sz(n, 1) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        if (p[x] == x) return x;
        return p[x] = find(p[x]);
    }
    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
    }
    int size(int x) { return sz[find(x)]; }
};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int n = (int)nums.size();
        int maxA = 100000; // per constraints

        // SPF sieve
        vector<int> spf(maxA + 1);
        for (int i = 0; i <= maxA; i++) spf[i] = i;
        for (int i = 2; i * 1LL * i <= maxA; i++) {
            if (spf[i] == i) { // prime
                for (long long j = 1LL * i * i; j <= maxA; j += i) {
                    if (spf[(int)j] == (int)j) spf[(int)j] = i;
                }
            }
        }

        auto primeFactorsUnique = [&](int x) {
            vector<int> factors;
            while (x > 1) {
                int p = spf[x];
                factors.push_back(p);
                while (x % p == 0) x /= p;
            }
            return factors;
        };

        DSU dsu(n);
        unordered_map<int, int> firstWithPrime; // prime -> index
        firstWithPrime.reserve(n * 2);

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            if (x == 1) continue; // no factors, stays isolated
            vector<int> pf = primeFactorsUnique(x);
            for (int p : pf) {
                auto it = firstWithPrime.find(p);
                if (it == firstWithPrime.end()) {
                    firstWithPrime[p] = i;
                } else {
                    dsu.unite(i, it->second);
                }
            }
        }

        // Count component sizes
        vector<int> count(n, 0);
        int ans = 1;
        for (int i = 0; i < n; i++) {
            int r = dsu.find(i);
            ans = max(ans, ++count[r]);
        }
        return ans;
    }
};
