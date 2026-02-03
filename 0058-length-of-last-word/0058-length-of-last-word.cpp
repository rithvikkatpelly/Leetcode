#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = (int)s.size() - 1;

        // skip trailing spaces
        while (i >= 0 && s[i] == ' ') i--;

        // count last word
        int len = 0;
        while (i >= 0 && s[i] != ' ') {
            len++;
            i--;
        }
        return len;
    }
};

