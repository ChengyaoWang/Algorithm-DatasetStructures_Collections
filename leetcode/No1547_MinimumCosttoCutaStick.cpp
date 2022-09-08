# include <vector>
# include <algorithm>
# include <limits>

using namespace std;

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(cuts.size(), vector<int>(cuts.size(), 0));

        for (int l = 2; l < cuts.size(); ++l) {
            for (int j = 0; j < cuts.size() - l; ++j) {
                dp[j][j + l] = numeric_limits<int>::max();
                for (int k = j + 1; k < j + l; ++k) {
                    dp[j][j + l] = min(
                        dp[j][j + l],
                        dp[j][k] + dp[k][j + l] + cuts[j + l] - cuts[j]
                    );
                }
            }
        }

        return dp[0][cuts.size() - 1];
    }
};