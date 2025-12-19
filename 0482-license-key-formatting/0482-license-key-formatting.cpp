#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string cleaned;
        cleaned.reserve(s.size());
        for (char c : s) {
            if (c == '-') continue;
            cleaned.push_back((char)toupper((unsigned char)c));
        }

        string res;
        res.reserve(cleaned.size() + cleaned.size() / k);

        int cnt = 0;
        for (int i = (int)cleaned.size() - 1; i >= 0; --i) {
            res.push_back(cleaned[i]);
            cnt++;
            if (cnt == k && i != 0) {
                res.push_back('-');
                cnt = 0;
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
