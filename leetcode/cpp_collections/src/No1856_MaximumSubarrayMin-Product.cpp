# include <vector>
# include <limits>
# include <algorithm>
using namespace std;

typedef long long ll;

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        vector<ll> cumSum = {0};
        for (auto elem: nums)
            cumSum.push_back(cumSum.back() + elem);
        
        // Compose Stack
        int n = nums.size();
        vector<int> sf = {}, sb = {};
        vector<int> forward = {}, backward = {};
        for (int i = 0; i < n; ++i) {
            while (!sf.empty() && nums[i] <= nums[sf.back()]) {
                sf.pop_back();
            }
            while (!sb.empty() && nums[n - 1 - i] <= nums[sb.back()]) {
                sb.pop_back();
            }

            forward.push_back(sf.empty() ? -1: sf.back());
            backward.push_back(sb.empty() ? n: sb.back());
            sf.push_back(i);
            sb.push_back(n - 1 - i);

        }
        reverse(backward.begin(), backward.end());
        ll res = 0;
        for (int i = 0; i < n; ++i) {
            res = max(res, (cumSum[backward[i]] - cumSum[forward[i] + 1]) * nums[i]);
        }

        return res % 1000000007;
    }

};