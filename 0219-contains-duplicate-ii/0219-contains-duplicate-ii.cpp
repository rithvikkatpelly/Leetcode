#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lastIndex;  // value -> last index seen

        for (int i = 0; i < (int)nums.size(); ++i) {
            int x = nums[i];
            if (lastIndex.count(x)) {
                if (i - lastIndex[x] <= k) {
                    return true;
                }
            }
            lastIndex[x] = i; // update last index of x
        }

        return false;
    }
};

