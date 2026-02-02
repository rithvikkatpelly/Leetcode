#include <vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        int size = 1 << n;
        vector<int> res;
        res.reserve(size);

        for (int i = 0; i < size; i++) {
            res.push_back(i ^ (i >> 1));
        }
        return res;
    }
};
