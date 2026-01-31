#include <string>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        // ASCII covers uppercase/lowercase easily
        vector<int> need(128, 0), window(128, 0);

        int required = 0; // number of distinct chars needed
        for (char c : t) {
            if (need[c] == 0) required++;
            need[c]++;
        }

        int formed = 0;   // how many distinct chars meet required count in window
        int bestLen = INT_MAX, bestL = 0;

        int l = 0;
        for (int r = 0; r < (int)s.size(); r++) {
            char c = s[r];
            window[c]++;

            if (need[c] > 0 && window[c] == need[c]) {
                formed++;
            }

            // Try to shrink while valid
            while (l <= r && formed == required) {
                int len = r - l + 1;
                if (len < bestLen) {
                    bestLen = len;
                    bestL = l;
                }

                char leftChar = s[l];
                window[leftChar]--;
                if (need[leftChar] > 0 && window[leftChar] < need[leftChar]) {
                    formed--;
                }
                l++;
            }
        }

        return bestLen == INT_MAX ? "" : s.substr(bestL, bestLen);
    }
};


