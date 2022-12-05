# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        auto minmax = minmax_element(nums.begin(), nums.end());
        int step = (*minmax.second - *minmax.first) / nums.size() + 1;
        vector<vector<int>> dp(nums.size(), vector<int> {});
        for (auto elem: nums) {
            dp[(elem - *minmax.first) / step].push_back(elem);
        }

        int prev_hi = -1, res = 0;
        for (int i = 0; i < dp.size(); ++i) {
            if (dp[i].empty()) {
                continue;
            } else {
                if (prev_hi != -1) {
                    auto minElem = *min_element(dp[i].begin(), dp[i].end());
                    res = max(res, minElem - prev_hi);
                }
                prev_hi = *max_element(dp[i].begin(), dp[i].end());
            }
        }
        return res;
    }
};