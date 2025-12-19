#include <string>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        // search s in t, but not allowing the trivial match at the ends
        return t.substr(1, t.size() - 2).find(s) != string::npos;
    }
};
