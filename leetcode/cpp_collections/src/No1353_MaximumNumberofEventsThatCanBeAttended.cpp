# include <vector>
# include <queue>
# include <algorithm>
using namespace std;

using pq = priority_queue<int, vector<int>, function<bool (int, int)>>;
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        pq q(
            [&](int i, int j){
                if (events[i][1] == events[j][1])   
                    return events[i][0] > events[j][0];
                return events[i][1] > events[j][1];
            }
        );

        int ret = 0, p = 0;
        for (int d = 0; d <= 100000; ++d) {
            while (!q.empty() && events[q.top()][1] < d) {
                q.pop();
            }
            while(p < events.size() && d >= events[p][0]) {
                q.push(p++);
            }
            if (!q.empty() && d >= events[q.top()][0]) {
                q.pop();
                ++ret;
            }
        }

        return ret;
    }
};