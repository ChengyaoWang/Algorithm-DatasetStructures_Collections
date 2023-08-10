# include <queue>
# include <vector>
# include <numeric>
using namespace std;

struct state {
    int i, j, t;
    state(int ii, int jj, int tt): i(ii), j(jj), t(tt) {}
};

class Solution {
public:
    vector<pair<int, int>> move = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };

    int minimumTime(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        if (grid[0][1] > 1 && grid[1][0] > 1)
            return -1;

        vector<vector<int>> mem(m, vector<int>(n, numeric_limits<int>::max()));
        auto cmp = [](const state& p, const state& q) {
            return p.t > q.t;
        };
        auto inRange = [&](const int& i, const int& j) {
            return (0 <= i) && (i < m) && (0 <= j) && (j < n);
        };
        priority_queue<state, vector<state>, decltype(cmp)> pq(cmp);
        pq.emplace(0, 0, 0);

        while (!pq.empty()) {
            auto elem = pq.top();
            pq.pop();

            if (mem[elem.i][elem.j] <= elem.t)
                continue;

            mem[elem.i][elem.j] = elem.t;
            for (auto& [di, dj]: move) {
                auto nextI = elem.i + di;
                auto nextJ = elem.j + dj;
                if (!inRange(nextI, nextJ))
                    continue;
                auto minT = max(1, grid[nextI][nextJ] - elem.t);
                if (minT % 2 == 0)
                    ++minT;
                if (mem[nextI][nextJ] <= elem.t)
                    continue;
                minT += elem.t;
                pq.emplace(nextI, nextJ, minT);
            }
        }

        return mem[m - 1][n - 1];
    }
};