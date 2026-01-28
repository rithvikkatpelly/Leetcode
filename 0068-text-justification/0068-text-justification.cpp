class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i;            // words [i..j-1] will be on the line
            int lineLen = 0;      // sum of word lengths

            // greedy pack
            while (j < n) {
                int nextLen = lineLen + (int)words[j].size() + (j - i); // spaces between words = (j-i)
                if (nextLen > maxWidth) break;
                lineLen += words[j].size();
                j++;
            }

            int numWords = j - i;
            int totalSpaces = maxWidth - lineLen;
            bool lastLine = (j == n);

            string line;
            if (lastLine || numWords == 1) {
                // left-justify
                for (int k = i; k < j; k++) {
                    if (k > i) line += ' ';
                    line += words[k];
                }
                line += string(maxWidth - line.size(), ' ');
            } else {
                // fully justify
                int gaps = numWords - 1;
                int base = totalSpaces / gaps;
                int extra = totalSpaces % gaps; // leftmost gaps get one extra space

                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        int spaces = base + (extra > 0 ? 1 : 0);
                        if (extra > 0) extra--;
                        line += string(spaces, ' ');
                    }
                }
            }

            res.push_back(line);
            i = j;
        }

        return res;
    }
};
