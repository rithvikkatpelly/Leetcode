#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHappyString(int n, int k) {
        int total = 3 * (1 << (n - 1));
        if (k > total) return "";

        string ans;
        char prev = 0;

        for (int i = 0; i < n; i++) {
            int block = 1 << (n - i - 1); // completions per choice at this position

            for (char c : {'a', 'b', 'c'}) {
                if (c == prev) continue;

                if (k > block) {
                    k -= block;           // skip this whole block
                } else {
                    ans.push_back(c);     // take this char
                    prev = c;
                    break;
                }
            }
        }
        return ans;
    }
};
