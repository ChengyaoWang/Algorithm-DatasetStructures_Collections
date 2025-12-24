# include <vector>
# include <numeric>
# include <queue>
using namespace std;

using loc = pair<int, int>;
using matrix = vector<vector<int>>;
vector<loc> next_move = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int INF = numeric_limits<int>::max();

class Solution {
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        deque<loc> q = {};
        matrix fire_t(m, vector<int>(n, INF));
        matrix people_t(m, vector<int>(n, INF));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    q.push_back({i, j});
                    fire_t[i][j] = 0;
                }
            }
        }

        doBFS(fire_t, q, grid);
        q.push_back({0, 0});
        people_t[0][0] = 0;
        doBFS(people_t, q, grid);
        
        int fire_s[3] = {fire_t[m - 1][n - 1], fire_t[m - 2][n - 1], fire_t[m - 1][n - 2]};
        int people_s[3] = {people_t[m - 1][n - 1], people_t[m - 2][n - 1], people_t[m - 1][n - 2]};

        if (fire_s[0] == INF && people_s[0] != INF) {
            return 1000000000;
        }
        int diff = fire_s[0] - people_s[0];
        if (diff > 0 && people_s[0] != INF) {
            return diff - ((fire_s[1] - people_s[1]) <= diff && (fire_s[2] - people_s[2]) <= diff);
        }
        return -1;
    }

    void doBFS(matrix& mx, deque<loc>& q, matrix& grid){
        int m = grid.size(), n = grid[0].size();
        auto inRange = [&](int i, int j) {
            return 0 <= i && i < m && 0 <= j && j < n && grid[i][j] != 2;
        };

        while(!q.empty()) {
            auto elem = q.front();
            q.pop_front();
            auto depth = mx[elem.first][elem.second] + 1;
            for (auto& loc_i: next_move) {
                auto di = elem.first + loc_i.first;
                auto dj = elem.second + loc_i.second;
                if (inRange(di, dj) && mx[di][dj] > depth) {
                    mx[di][dj] = depth;
                    q.push_back({di, dj});
                }
            }
        }
    }
};