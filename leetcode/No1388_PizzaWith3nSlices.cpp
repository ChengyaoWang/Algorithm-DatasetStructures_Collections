# include <vector>
# include <algorithm>

using namespace std ;

class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        vector<int> s1(slices.begin() + 1, slices.end());
        vector<int> s2(slices.begin(), slices.end() - 1);

        return max(getSubProblem(s1), getSubProblem(s2));
    }

    int getSubProblem(vector<int>& subSlice) {
        int m = subSlice.size(), n = (subSlice.size() + 1) / 3;

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == 1) {
                    dp[i][j] = subSlice[0];
                } else {
                    dp[i][j] = max(
                        dp[i - 1][j],
                        dp[i - 2][j - 1] + subSlice[i - 1]
                    );
                }
            }
        }        

        return dp[m][n];
    }
};