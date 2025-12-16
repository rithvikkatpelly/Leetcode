#include <string>
using namespace std;

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string s;
        int count = 0;

        while ((int)s.size() < (int)b.size()) {
            s += a;
            count++;
        }

        if (s.find(b) != string::npos) return count;

        s += a;
        count++;
        if (s.find(b) != string::npos) return count;

        return -1;
    }
};
