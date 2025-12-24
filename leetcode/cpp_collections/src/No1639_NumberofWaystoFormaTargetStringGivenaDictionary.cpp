# include <vector>
# include <string>
# include <numeric>
using namespace std;

using ll = long long;
class Solution {
public:
    int numWays(vector<string>& words, string target) {

        int m = words.size(), n = words[0].size();
        vector<vector<int>> enc(n, vector<int>(26, 0));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                ++enc[j][words[i][j] - 'a'];

        int l = target.size();
        if (n < l)
            return 0;

        ll MOD_NUM = 1000000007LL;
        vector<ll> dp(n + 1, 0LL);
        dp[0] = 1LL;

        for (int i = 0; i < l; ++i) {
            ll cumSum = accumulate(dp.begin(), dp.end(), 0LL);
            for (int j = n; j >= 0; --j) {
                if (j <= i) {
                    dp[j] = 0LL;
                } else {
                    cumSum -= dp[j];
                    dp[j] = (enc[j - 1][target[i] - 'a'] * cumSum) % MOD_NUM;
                }
            }
        }

        ll ret = accumulate(dp.begin() + l, dp.end(), 0LL) % MOD_NUM;

        return (int)ret;
    }
};