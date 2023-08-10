# include <vector>
# include <numeric>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> move = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };

    int dfs(
        int i, int j, int val,
        vector<vector<int>>& grid
    ) {
        if (grid[i][j] == 0) {
            return val;
        }

        auto withinRange = [&](int x, int y) {
            return 0 <= x && x < grid.size() && 0 <= y && y < grid[0].size();
        };

        int maxVal = numeric_limits<int>::min();
        for (auto& [di, dj]: move) {
            auto ii = di + i;
            auto jj = dj + j;
            if (!withinRange(ii, jj))
                continue;
            auto temp = grid[ii][jj];
            grid[ii][jj] = 0;
            maxVal = max(maxVal, dfs(ii, jj, val + temp, grid));
            grid[ii][jj]= temp;
        }
        
        return maxVal;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        
        int ret = numeric_limits<int>::min();
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ret = max(ret, dfs(i, j, 0, grid));
            }
        }
        return ret;
    }
};