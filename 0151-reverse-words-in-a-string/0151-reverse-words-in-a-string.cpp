class Solution {
public:
    string reverseWords(string s) {
        int i = s.size() - 1;
        string result;

        while (i >= 0) {
            // skip spaces
            while (i >= 0 && s[i] == ' ') i--;

            if (i < 0) break;

            int j = i;

            // find start of word
            while (j >= 0 && s[j] != ' ') j--;

            // add word
            if (!result.empty()) result += " ";
            result += s.substr(j + 1, i - j);

            i = j - 1;
        }

        return result;
    }
};