#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = (int)points.size();
        if (n <= 2) return n;

        auto gcdll = [](long long a, long long b) {
            a = llabs(a); b = llabs(b);
            while (b) { long long t = a % b; a = b; b = t; }
            return a;
        };

        int ans = 1;

        for (int i = 0; i < n; ++i) {
            unordered_map<long long, int> cnt; // key for (dy,dx)
            int dup = 0;
            int best = 0;

            long long xi = points[i][0], yi = points[i][1];

            for (int j = i + 1; j < n; ++j) {
                long long xj = points[j][0], yj = points[j][1];
                long long dx = xj - xi;
                long long dy = yj - yi;

                if (dx == 0 && dy == 0) { // duplicate point
                    dup++;
                    continue;
                }

                // Normalize slope
                if (dx == 0) {           // vertical
                    dy = 1; dx = 0;
                } else if (dy == 0) {    // horizontal
                    dy = 0; dx = 1;
                } else {
                    long long g = gcdll(dy, dx);
                    dy /= g; dx /= g;

                    // enforce a unique sign: make dx positive
                    if (dx < 0) { dx = -dx; dy = -dy; }
                }

                // Pack (dy, dx) into one 64-bit key
                // shift dy to unsigned-ish space to avoid collisions
                long long key = (dy + 200000) * 400001LL + (dx + 200000);

                int v = ++cnt[key];
                best = max(best, v);
            }

            // points on best line through i = itself + best + duplicates
            ans = max(ans, 1 + best + dup);
        }

        return ans;
    }
};
