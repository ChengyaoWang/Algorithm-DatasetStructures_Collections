# include <queue>
# include <vector>
# include <numeric>
using namespace std;

using tensor = vector<vector<vector<int>>>;
using mx = vector<vector<int>>;
using quadple = tuple<int, int, int, int>;

class Solution {
private:
    vector<pair<int, int>> move = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        tensor dp = tensor(
            m, vector<vector<int>> (
                n, vector<int> (
                    k + 1, numeric_limits<int>::max()
                )
            )
        );
        dp[0][0][k] = 0;

        auto inBoarder = [&](int i, int j) {
            return 0 <= i && i < m && 0 <= j && j < n;
        };

        queue<quadple> q = {};
        q.push(make_tuple(0, 0, k, 0));

        int x, y;
        while (!q.empty()) {
            
            auto [i, j, r, path] = q.front();
            q.pop();

            if (dp[i][j][r] < path)
                continue;

            for (auto& [di, dj]: move) {
                x = di + i; y = dj + j;
                if (!inBoarder(x, y))
                    continue;
                if (grid[x][y] == 1 && r > 0) {
                    if (dp[i][j][r] + 1 < dp[x][y][r - 1]) {
                        dp[x][y][r - 1] = dp[i][j][r] + 1;
                        q.push(make_tuple(x, y, r - 1, dp[x][y][r - 1]));
                    }
                }
                if (grid[x][y] == 0) {
                    if (dp[i][j][r] + 1 < dp[x][y][r]) {
                        dp[x][y][r] = dp[i][j][r] + 1;
                        q.push(make_tuple(x, y, r, dp[x][y][r]));
                    }
                }
            }
        }

        auto ret = * min_element(
            dp[m - 1][n - 1].begin(),
            dp[m - 1][n - 1].end()
        );

        return (ret == numeric_limits<int>::max()) ? -1: ret;
    }
};