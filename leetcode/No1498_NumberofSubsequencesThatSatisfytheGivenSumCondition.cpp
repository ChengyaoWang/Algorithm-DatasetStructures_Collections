# include <vector>
# include <algorithm>

using namespace std;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<int> dp = {1};
        int MOD = 1000000007;
        for (int i = 0; i < nums.size(); ++i)
            dp.push_back((dp.back() * 2) % MOD);

        int low = 0, up = nums.size() - 1, res = 0;
        while (low <= up) {
            if (nums[low] + nums[up] > target) {
                --up;
            } else {
                res = (res + dp[up - low]) % MOD;
            }
        }
        return res;
    }
};