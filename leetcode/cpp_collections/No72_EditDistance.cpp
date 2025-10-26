# include <string>
# include <vector>
# include <limits>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size(), tmp;

        vector<vector<int>> dp(n1, vector<int>(n2, INT_MAX));
        auto isSame = [&](int x, int y) {return word1[x] == word2[y] ? 0: 1;};
        dp[0][0] = isSame(0, 0);

        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < n2; ++j) {
                tmp = dp[i][j];
                if (i > 0) {
                    tmp = min(tmp, dp[i - 1][j] + 1);
                }
                if (j > 0) {
                    tmp = min(tmp, dp[i][j - 1] + 1);
                }
                if (i > 0 && j > 0) {
                    tmp = min(tmp, dp[i - 1][j - 1] + isSame(i, j));
                }
            }
        }

        return dp[n1 - 1][n2 - 1];
    }
};