# include <string>
# include <vector>
# include <numeric>
# include <algorithm>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequences(string s) {
        
        int n = s.length();
        vector<vector<vector<long long>>> dp(
            n, vector<vector<long long>> (
                n, vector<long long> (4, 0)
            )
        );

        for (int l = 0; l < n; ++l) {
            for (int i = 0; i < n - l; ++i) {
                auto j = i + l;
                if (l == 0) {
                    dp[i][j][s[i] - 'a'] = (long long)l + 1;
                    continue;
                }

                for (int k = 0; k < 4; ++k) {
                    if (s[i] == s[j] && s[i] == (k + 'a'))
                        dp[i][j][k] = 2 + accumulate(dp[i + 1][j - 1].begin(), dp[i + 1][j - 1].end(), 0LL);
                    else 
                        dp[i][j][k] = dp[i + 1][j][k] + dp[i][j - 1][k] - dp[i + 1][j - 1][k];
                    dp[i][j][k] %= 1000000007LL;
                }
            }
        }
        auto ret = accumulate(dp[0][n - 1].begin(), dp[0][n - 1].end(), 0LL);
        return (int)(ret % 1000000007);
    }
};