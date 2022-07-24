# include <vector>
# include <algorithm>
# include <queue>

using namespace std;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<pair<int, int>> q;

        int retVal = 0, elem = 0;
        for (auto &i: events) {
            retVal = max(retVal, i[2]);
            while (!q.empty() && q.top().first > -i[0]) {
                elem = max(elem, q.top().second);
                q.pop();
            }
            
            retVal = max(retVal, elem + i[2]);

            q.push(pair<int, int> {-i[1], i[2]});
        }

        return retVal;
    }
};