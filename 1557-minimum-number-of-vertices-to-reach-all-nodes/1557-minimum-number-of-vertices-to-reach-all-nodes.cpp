#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indeg(n, 0);
        for (auto &e : edges) {
            indeg[e[1]]++;
        }

        vector<int> ans;
        ans.reserve(n);
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) ans.push_back(i);
        }
        return ans;
    }
};
