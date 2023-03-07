# include <queue>
# include <vector>
using namespace std;

using p = pair<int, int>;
using pq = priority_queue<p, vector<p>>;
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        
        int elem = nums[0];
        pq queue = {};
        queue.push({nums[0], 0});
        for (int i = 1; i < nums.size(); ++i) {
            while (queue.top().second < i - k) {
                queue.pop();
            }
            elem = queue.top().first + nums[i];
            queue.push({elem, i});
        }
        return elem;
    }
};