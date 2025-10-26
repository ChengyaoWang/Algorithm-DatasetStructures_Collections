# include <vector>
# include <limits>

using namespace std;

class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {

        int n1 = cost.size(), n2 = cost[0].size();
        vector<vector<int>> dp(n1 + 1, vector<int>(1 << n2, INT_MAX));
        dp[0][0] = 0;

        vector<int> gTwo2gOne(n2, INT_MAX);
        for (int j = 0; j < n2; ++j)
            for (int i = 0; i < n1; ++i)
                gTwo2gOne[j] = min(gTwo2gOne[j], cost[i][j]);

        for (int i = 0; i < n1; ++i) {
            for (int mask = 0; mask < (1 << n2); ++mask) {
                if (dp[i][mask] == INT_MAX)
                    continue;
                for (int j = 0; j < n2; ++j) {
                    dp[i + 1][mask | (1 << j)] = min(
                        dp[i + 1][mask | (1 << j)],
                        dp[i][mask] + cost[i][j]
                    );
                }
            }
        }

        int ans = INT_MAX;
        for (int mask = 0; mask < (1 << n2); ++mask) {
            if (dp[n1][mask] == INT_MAX)
                continue;
            int extra = 0;
            for (int j = 0; j < n2; ++j) {
                if ((mask & (1 << j)) == 0)
                    extra += gTwo2gOne[j];
            }
            ans = min(ans, dp[n1][mask] + extra);
        }

        return ans;
    }
};