#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();

        int minDiff = INT_MAX;
        // First pass: find minimum difference
        for (int i = 0; i < n - 1; ++i) {
            int diff = arr[i + 1] - arr[i];
            if (diff < minDiff) {
                minDiff = diff;
            }
        }

        vector<vector<int>> result;
        // Second pass: collect all pairs with that min difference
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i + 1] - arr[i] == minDiff) {
                result.push_back({arr[i], arr[i + 1]});
            }
        }

        return result;
    }
};
