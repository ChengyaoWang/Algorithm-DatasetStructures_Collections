# include <string>
# include <vector>
# include <numeric>
using namespace std;

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int N = stoneValue.size();
        int minVal = numeric_limits<int>::min() / 100;
        int maxVal = numeric_limits<int>::max() / 100;
        vector<pair<int, int>> dp(N + 1);
        for (int i = N - 1; i >= 0; --i) {
            dp[i] = {minVal, maxVal};
            auto tmp = 0;
            for (int j = 1; j <= 3 && i + j <= N; ++j) {
                tmp += stoneValue[i + j - 1];
                dp[i].first = max(dp[i].first, dp[i + j].second + tmp);
                dp[i].second = min(dp[i].second, dp[i + j].first - tmp);
            }
        }

        if (dp[0].first == 0) {
            return "Tie";
        } else if (dp[0].first > 0) {
            return "Alice";
        } else {
            return "Bob";
        }
    }
};