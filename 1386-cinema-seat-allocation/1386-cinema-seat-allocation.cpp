class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;

        for (auto& seat : reservedSeats) {
            int row = seat[0], col = seat[1];
            if (col >= 2 && col <= 9) {
                mp[row] |= (1 << col);
            }
        }

        long long ans = 2LL * n;

        for (auto& [row, mask] : mp) {
            bool left = !(mask & ((1 << 2) | (1 << 3) | (1 << 4) | (1 << 5)));
            bool middle = !(mask & ((1 << 4) | (1 << 5) | (1 << 6) | (1 << 7)));
            bool right = !(mask & ((1 << 6) | (1 << 7) | (1 << 8) | (1 << 9)));

            int canPlace = 0;
            if (left && right) canPlace = 2;
            else if (left || middle || right) canPlace = 1;
            else canPlace = 0;

            ans -= (2 - canPlace);
        }

        return (int)ans;
    }
};