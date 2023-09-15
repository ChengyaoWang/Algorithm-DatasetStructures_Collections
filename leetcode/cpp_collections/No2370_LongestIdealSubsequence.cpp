# include <string>
# include <vector>
using namespace std;

class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(26, 0));
        int ret = 1;
        for (int i = 0; i < s.size(); ++i) {
            auto c = s[i] - 'a';
            for (int j = 0; j < 26; ++j) {
                dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
                if (abs(c - j) <= k) {
                    dp[i + 1][c] = max(dp[i + 1][c], dp[i][j] + 1);
                }
                ret = max(ret, dp[i + 1][c]);
            }
        }
        return ret;
    }
};