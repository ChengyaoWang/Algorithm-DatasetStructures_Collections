# include <vector>
using namespace std;

using ts = vector<vector<vector<int>>>;

class Solution {
public:
    int m, n, k;
    vector<pair<int, int>> move = {
        make_pair(-1, 0), make_pair(1, 0),
        make_pair(0, -1), make_pair(0, 1),
    };

    int dfs(tuple<int, int, int> loc, ts& dp) {

        auto& [i, j, k] = loc;
        auto m = dp.size(), n = dp[0].size();

        auto result = 0;
        if (i < 0 || i >= m || j < 0 || j >= n) {
            result = 1;
        } else if (k == 0) {
            result = 0;
            dp[i][j][k] = result;
        } else if (dp[i][j][k] == -1) {
            for (auto& [di, dj]: move) {
                result += dfs(make_tuple(i + di, j + dj, k - 1), dp);
                result %= 1000000007;
            }
            dp[i][j][k] = result;
        } else {
            result = dp[i][j][k];
        }

        return result;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        this -> m = m;
        this -> n = n;
        this -> k = maxMove;

        ts dp(
            m, vector<vector<int>> (
                n, vector<int> (maxMove + 1, -1)
            )
        );

        dfs(make_tuple(startRow, startColumn, maxMove), dp);
        return dp[startRow][startColumn][maxMove];
    }
};