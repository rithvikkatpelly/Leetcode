// Forward declaration of read4 API.
int read4(char *buf4);

class Solution {
private:
    char buf4[4];
    int bufPtr = 0;     // current index in buf4
    int bufCount = 0;   // number of valid chars in buf4

public:
    int read(char *buf, int n) {
        int total = 0;

        while (total < n) {

            // If buffer is empty, read more from file
            if (bufPtr == bufCount) {
                bufCount = read4(buf4);
                bufPtr = 0;

                if (bufCount == 0) break; // EOF
            }

            // Copy from internal buffer to output
            while (total < n && bufPtr < bufCount) {
                buf[total++] = buf4[bufPtr++];
            }
        }

        return total;
    }
};
