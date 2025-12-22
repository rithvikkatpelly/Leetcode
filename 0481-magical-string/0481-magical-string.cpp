#include <vector>
using namespace std;

class Solution {
public:
    int magicalString(int n) {
        if (n <= 0) return 0;
        if (n <= 3) return 1;  // "122" -> only one '1' in first 1..3

        vector<int> s(n + 2);  // a bit of extra space
        s[0] = 1;
        s[1] = 2;
        s[2] = 2;

        int head = 2;   // read counts from here
        int tail = 3;   // next position to fill
        int num = 1;    // next number to write
        int countOnes = 1; // we already have one '1' at s[0]

        while (tail < n) {
            int repeat = s[head];
            while (repeat-- > 0 && tail < n) {
                s[tail] = num;
                if (num == 1) countOnes++;
                tail++;
            }
            // flip 1 <-> 2, using num = 3 - num
            num = 3 - num;
            head++;
        }

        return countOnes;
    }
};
