# include <vector>
# include <queue>
# include <numeric>
# include <algorithm>
using namespace std;

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(),
            [&](const vector<int>& i, const vector<int>& j){
            if (i[0] == j[0])
                return i[1] < j[1];
            return i[0] < j[0];
        });

        int ret = numeric_limits<int>::min();
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto& vec: intervals) {
            
            int st = vec[0], et = vec[1];
            while (!pq.empty() && st > pq.top()) {
                pq.pop();
            }

            pq.push(et);
            ret = max(ret, (int)pq.size());
        }

        return ret;        
    }
};