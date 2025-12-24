# include <vector>
# include <algorithm>
# include <numeric>
using namespace std;

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        auto tgt = accumulate(
            nums.begin(), nums.end(), 0, [](int &res, int a) {
                return res | a;
            }
        );

        int tmp = tgt, cnt = 0;
        while (tmp) {
            tmp >>= 1;
            ++cnt;
        }

        vector<int> dp(1 << cnt, 0);
        auto max = 0;
        dp[0] = 1;
        for (auto elem: nums) {
            for (int j = max; j >= 0; --j) {
                dp[j | elem] += dp[j];
            }
            max |= elem;
        }
        return dp[tgt];
    }
};