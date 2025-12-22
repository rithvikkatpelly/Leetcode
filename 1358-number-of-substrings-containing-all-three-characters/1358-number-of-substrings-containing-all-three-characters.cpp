#include <string>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = (int)s.size();
        int cnt[3] = {0, 0, 0};   // a,b,c
        int l = 0;
        long long ans = 0;

        for (int r = 0; r < n; r++) {
            cnt[s[r] - 'a']++;

            while (cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0) {
                cnt[s[l] - 'a']--;
                l++;
            }
            // all substrings ending at r that start before l are valid
            ans += l;
        }

        return (int)ans;
    }
};
