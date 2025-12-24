# include <vector>
# include <string>
# include <numeric>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, strs.size() + 1));
        for (auto& s: strs) {
            auto cnt0 = accumulate(s.begin(), s.end(), 0, 
                [](int cul, char a){return a == '0' ? cul + 1: cul;}
            );
            auto cnt1 = s.size() - cnt0;
            for (int i = m; i >= cnt0; --i) {
                for (int j = n; j >= cnt1; --j) {
                    dp[i][j] = min(dp[i][j], dp[i - cnt0][j - cnt1] + 1);
                }
            }
        }
        return dp[m][n];
    }
};