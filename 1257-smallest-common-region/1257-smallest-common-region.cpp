#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string, string> parent;

        for (auto& group : regions) {
            string root = group[0];
            for (int i = 1; i < group.size(); i++) {
                parent[group[i]] = root;
            }
        }

        unordered_set<string> ancestors;
        string cur = region1;
        while (!cur.empty()) {
            ancestors.insert(cur);
            if (parent.count(cur)) cur = parent[cur];
            else cur = "";
        }

        cur = region2;
        while (!ancestors.count(cur)) {
            cur = parent[cur];
        }

        return cur;
    }
};