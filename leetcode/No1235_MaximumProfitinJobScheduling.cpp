# include <vector>
# include <algorithm>
# include <map>

using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        for (int i = 0; i < startTime.size(); ++i) {
            jobs.push_back( vector<int> {endTime[i], startTime[i], profit[i]} );
        }
        sort(jobs.begin(), jobs.end());
        
        map<int, int> mem = {{0, 0}};
        int elem = 0;
        for (auto &i: jobs) {
            auto it = prev(mem.upper_bound(i[1]));
            elem = it -> second + i[2];
            if (elem > mem.rbegin() -> second) {
                mem[i[0]] = elem;
            }
        }
        return mem.rbegin() -> second;
    }
};