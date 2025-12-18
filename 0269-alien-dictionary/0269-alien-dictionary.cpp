#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> inDegree;

        // Initialize in-degree for all unique chars
        for (const string& word : words)
            for (char c : word)
                inDegree[c] = 0;

        // Build graph
        for (int i = 0; i < words.size() - 1; ++i) {
            string word1 = words[i], word2 = words[i + 1];
            int len = min(word1.size(), word2.size());
            bool foundDiff = false;

            for (int j = 0; j < len; ++j) {
                char a = word1[j], b = word2[j];
                if (a != b) {
                    if (!graph[a].count(b)) {
                        graph[a].insert(b);
                        inDegree[b]++;
                    }
                    foundDiff = true;
                    break;
                }
            }

            // Check invalid case: "abc" before "ab"
            if (!foundDiff && word1.size() > word2.size())
                return "";
        }

        // Topological sort using Kahn's algorithm
        queue<char> q;
        for (const auto& [ch, deg] : inDegree)
            if (deg == 0) q.push(ch);

        string result;
        while (!q.empty()) {
            char curr = q.front(); q.pop();
            result += curr;
            for (char neighbor : graph[curr]) {
                if (--inDegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        return result.size() == inDegree.size() ? result : "";
    }
};

