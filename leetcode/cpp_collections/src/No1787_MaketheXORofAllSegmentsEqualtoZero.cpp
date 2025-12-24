# include <vector>
# include <numeric>
# include <unordered_set>
using namespace std;

class Solution {
public:
    int minChanges(vector<int>& nums, int k) {

        int n = nums.size();

        // Count Frequency
        vector<vector<int>> freq(k, vector<int>(1024, 0));
        vector<unordered_set<int>> numSet(k);
        for (int i = 0; i < nums.size(); ++i) {
            ++freq[i % k][nums[i]];
            numSet[i % k].insert(nums[i]);
        }

        // DP
        vector<vector<int>> dp(k, vector<int>(1024, numeric_limits<int>::max()));
        int best = 0;
        for (int i = 0; i < k; ++i) {
            int numOfPos = n / k + (((n % k) > i) ? 1 : 0);
            int bestCur = numeric_limits<int>::max() >> 2;
            for (int j = 0; j < 1024; ++j) {
                if (i == 0) {
                    dp[i][j] = numOfPos - freq[i][j];
                } else {
                    for (auto& kk: numSet[i]) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j ^ kk] + numOfPos - freq[i][kk]);
                    }
                    dp[i][j] = min(dp[i][j], best + numOfPos);
                }
                bestCur = min(bestCur, dp[i][j]);
            }
            best = bestCur;
        }

        return dp[k - 1][0];
    }
};