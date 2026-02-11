#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> result;

        if (!dict.count(endWord)) return result;

        unordered_map<string, vector<string>> parents;
        unordered_set<string> currentLevel{beginWord};
        bool found = false;

        while (!currentLevel.empty() && !found) {
            for (const string &w : currentLevel)
                dict.erase(w);

            unordered_set<string> nextLevel;

            for (const string &word : currentLevel) {
                string temp = word;
                for (int i = 0; i < temp.size(); i++) {
                    char original = temp[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        temp[i] = c;
                        if (dict.count(temp)) {
                            nextLevel.insert(temp);
                            parents[temp].push_back(word);
                            if (temp == endWord)
                                found = true;
                        }
                    }
                    temp[i] = original;
                }
            }
            currentLevel = nextLevel;
        }

        if (!found) return result;

        vector<string> path{endWord};
        backtrack(endWord, beginWord, parents, path, result);
        return result;
    }

private:
    void backtrack(string word, string beginWord,
                   unordered_map<string, vector<string>>& parents,
                   vector<string>& path,
                   vector<vector<string>>& result) {
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            result.push_back(temp);
            return;
        }

        for (const string &p : parents[word]) {
            path.push_back(p);
            backtrack(p, beginWord, parents, path, result);
            path.pop_back();
        }
    }
};


