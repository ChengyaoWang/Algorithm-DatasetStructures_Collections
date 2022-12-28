# include <vector>
# include <numeric>
# include <algorithm>
using namespace std;

class Solution {
public:

    vector<vector<int>> calsubsetSum(vector<int> nums) {
        auto N = nums.size();
        vector<vector<int>> dp(int(N + 1));
        
        for (int selectMask = 0; selectMask < (1 << N); ++selectMask) {
            auto tmpSum = 0, tmpCnt = 0;
            for (int j = 0; j < N; ++j) {
                if (selectMask & (1 << j)) {
                    tmpSum += nums[j];
                    ++tmpCnt;
                }
            }
            dp[tmpCnt].push_back(tmpSum);
        }

        return dp;
    }

    int minimumDifference(vector<int>& nums) {
        auto arrSum = accumulate(nums.begin(), nums.end(), 0);
        auto N = nums.size();

        auto left = calsubsetSum(vector<int>(nums.begin(), nums.begin() + N / 2));
        auto right = calsubsetSum(vector<int>(nums.begin() + N / 2, nums.end()));

        // Enumerate All Combinations
        int ans = numeric_limits<int>::max(), tgtSum = arrSum / 2;
        for (int cntLeft = 0; cntLeft <= N / 2; ++cntLeft) {
            int cntRight = N / 2 - cntLeft;
            sort(right[cntRight].begin(), right[cntRight].end());
            for (auto elem: left[cntLeft]) {
                auto tmp = lower_bound(right[cntRight].begin(), right[cntRight].end(), tgtSum - elem);
                if (tmp != right[cntRight].end())
                    ans = min(ans, abs(arrSum - 2 * (elem + *tmp)));
            }
        }
        
        return ans;
    }
};