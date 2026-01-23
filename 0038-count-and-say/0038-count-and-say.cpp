class Solution {
public:
    string countAndSay(int n) {
        string s = "1";

        for (int i = 2; i <= n; i++) {
            string next = "";
            int j = 0;

            while (j < (int)s.size()) {
                char ch = s[j];
                int cnt = 0;

                while (j < (int)s.size() && s[j] == ch) {
                    cnt++;
                    j++;
                }

                next += to_string(cnt);
                next += ch;
            }

            s = next;
        }

        return s;
    }
};
