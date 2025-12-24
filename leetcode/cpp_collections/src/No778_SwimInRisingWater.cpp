# include <vector>
# include <numeric>
using namespace std;

class Solution {
public:
    int union_find(int i, vector<int>& un) {
        while (i != un[i]) i = un[i];
        return i;
    }

    int swimInWater(vector<vector<int>>& grid) {
        // Union Find Solution
        int n = grid.size();
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        vector<pair<int, int>> rev(n * n);
        for (int i = 0 ; i < n; ++i)
            for (int j = 0; j < n; ++j)
                rev[grid[i][j]] = {i, j};

        vector<int> un(n * n);
        vector<bool> seen(n * n);
        iota(un.begin(), un.end(), 0);
        for (int i = 0; i < n * n; ++i) {
            int x = rev[i].first, y = rev[i].second;
            seen[n * x + y] = true;
            for (auto d: dir) {
                int dx = x + d[0], dy = y + d[1];
                if (0 <= dx && dx < n && 0 <= dy && dy < n && seen[dx * n + dy]) {
                    int un_x = union_find(x * n + y, un);
                    int un_y = union_find(dx * n + dy, un);
                    un[un_x] = min(un_x, un_y);
                    un[un_y] = min(un_x, un_y);
                }
            }
            if (union_find(0, un) == union_find(n * n - 1, un))
                return i;
        }

        return -1;
    }
};