# include <vector>
# include <numeric>
# include <algorithm>
# include <unordered_map>
using namespace std;

using mx = vector<vector<int>>;

class Solution {
private:
    int m, n;
    vector<pair<int, int>> move = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };

    bool withinRange(int i, int j) {
        return (0 <= i) && (i < m) && (0 <= j) && (j < n);
    }

    int connect(int i, int j, mx& grid) {
        if (!withinRange(i, j) || grid[i][j] != 1)
            return 0;

        grid[i][j] = 2;
        int ret = 1, x, y;
        for (auto& [di, dj]: move) {
            x = di + i; y = dj + j;
            ret += connect(x, y, grid);
        }
        return ret;
    }

public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {

        int nHits = hits.size();
        m = grid.size(); n = grid[0].size();
        for (auto& hit: hits)   --grid[hit[0]][hit[1]];

        // Initialize Connected Component
        for (int j = 0; j < n; ++j)     connect(0, j, grid);

        // Reversely Add Bricks Back
        int x, y, i, j;
        vector<int> ret(hits.size(), 0);
        for (int hit_i = hits.size() - 1; hit_i >= 0; --hit_i) {
            i = hits[hit_i][0]; j = hits[hit_i][1];
            ++grid[i][j];
            auto hasConnectedNeighbor = i == 0;
            for (auto& [di, dj]: move) {
                x = di + i; y = dj + j;
                hasConnectedNeighbor |= (withinRange(x, y) && grid[x][y] == 2);
            }
            if (grid[i][j] == 1 && hasConnectedNeighbor)
                ret[hit_i] = connect(i, j, grid) - 1;
        }

        return ret;
    }
};