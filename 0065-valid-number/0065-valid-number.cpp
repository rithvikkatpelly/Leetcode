class Solution {
public:
    bool isNumber(string s) {
        bool seenDigit = false;
        bool seenDot = false;
        bool seenExp = false;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                seenDigit = true;
            }
            else if (c == '+' || c == '-') {
                // sign must be at start or right after e/E
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            }
            else if (c == '.') {
                // dot can't appear twice or after exponent
                if (seenDot || seenExp) return false;
                seenDot = true;
            }
            else if (c == 'e' || c == 'E') {
                // exponent must appear once and after a digit
                if (seenExp || !seenDigit) return false;
                seenExp = true;
                seenDigit = false; // must see digits after e
            }
            else {
                return false;
            }
        }

        return seenDigit; // must end with a digit
    }
};
