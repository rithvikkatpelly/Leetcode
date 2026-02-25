class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = (int)s.size();

        // pal[i][j] = is s[i..j] a palindrome?
        vector<vector<bool>> pal(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j] && (j - i < 2 || pal[i + 1][j - 1])) {
                    pal[i][j] = true;
                }
            }
        }

        vector<vector<string>> ans;
        vector<string> path;

        function<void(int)> dfs = [&](int start) {
            if (start == n) {
                ans.push_back(path);
                return;
            }
            for (int end = start; end < n; ++end) {
                if (!pal[start][end]) continue;
                path.push_back(s.substr(start, end - start + 1));
                dfs(end + 1);
                path.pop_back();
            }
        };

        dfs(0);
        return ans;
    }
};
