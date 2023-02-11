# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& i, vector<int>& j) {
            return i[1] < j[1];
        });
        int ret = 0, curEnd = intervals[0][0] - 1;
        for (auto& i: intervals) {
            if (i[0] < curEnd) {
                continue;
            }
            curEnd = i[1];
            ++ret;
        }
        return intervals.size() - ret;
    }
};