class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        vector<int> starts, ends;
        for (const auto& interval : intervals) {
            starts.push_back(interval[0]);
            ends.push_back(interval[1]);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int s = 0, e = 0;
        int rooms = 0, maxRooms = 0;

        while (s < starts.size()) {
            if (starts[s] < ends[e]) {
                rooms++;
                maxRooms = max(maxRooms, rooms);
                s++;
            } else {
                rooms--;
                e++;
            }
        }
        return maxRooms;
    }
};

