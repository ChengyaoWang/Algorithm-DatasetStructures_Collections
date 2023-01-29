# include <queue>
# include <vector>
using namespace std;

using ll = long long;
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int ret = 1000001;
        vector<ll> cumSum = {0};
        for (auto& elem: nums)
            cumSum.push_back(cumSum.back() + elem);

        deque<int> q = {0};
        for (int i = 0; i < cumSum.size(); ++i) {
            while(!q.empty() && cumSum[i] - cumSum[q.front()] >= k) {
                ret = min(ret, i - q.front());
                q.pop_front();
            }
            while(!q.empty() && cumSum[i] < cumSum[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }

        return ret < 1000001 ? ret: -1;
    }
};