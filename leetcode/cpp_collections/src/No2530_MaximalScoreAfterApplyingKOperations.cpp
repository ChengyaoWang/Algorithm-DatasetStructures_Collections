# include <vector>
# include <queue>
using namespace std;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {

        long long ret = 0LL;
        priority_queue<int, vector<int>> max_pq;
        
        for (auto i: nums)
            max_pq.push(i);

        for (int i = 0; i < k; ++i) {
            auto tmp = max_pq.top();
            max_pq.pop();

            ret += (long long)tmp;
            max_pq.push((tmp + 2) / 3);
        }

        return ret;        
    }
};