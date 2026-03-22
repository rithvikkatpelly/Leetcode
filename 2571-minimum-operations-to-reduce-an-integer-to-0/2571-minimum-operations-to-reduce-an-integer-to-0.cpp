class Solution {
public:
    int minOperations(int n) {
        int ops = 0;

        while (n > 0) {
            // If n is already a power of 2
            if ((n & (n - 1)) == 0) {
                return ops + 1;
            }

            int lowbit = n & -n;

            // If next bit is also set, add lowbit; otherwise subtract
            if (n & (lowbit << 1)) {
                n += lowbit;
            } else {
                n -= lowbit;
            }

            ops++;
        }

        return ops;
    }
};