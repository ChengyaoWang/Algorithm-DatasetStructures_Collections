# include <vector>
# include <numeric>
using namespace std;

class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {

        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n), dp_tmp(n);
        copy(grid[0].begin(), grid[0].end(), dp.begin());

        for (int i = 1; i < m; ++i) {
            fill(dp_tmp.begin(), dp_tmp.end(), numeric_limits<int>::max());
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k)
                    dp_tmp[j] = min(dp_tmp[j], dp[k] + moveCost[grid[i - 1][k]][j]);
                dp_tmp[j] += grid[i][j];
            }
            swap(dp, dp_tmp);
        }

        auto ret = min_element(dp.begin(), dp.end());
        return *ret;
    }
};