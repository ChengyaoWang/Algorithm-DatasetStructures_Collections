# include <vector>
# include <queue>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> seen(n, vector<int>(n, -1));
        deque<pair<int, int>> q, q_back;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    q.push_back({i, j});
                    seen[i][j] = 0;
                }
            }
        }

        if (q.size() == n * n || q.size() == 0) 
            return -1;
        
        int ret = 0;
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for(;;) {
            while(!q.empty()) {
                auto elem = q.front();
                q.pop_front();
                for (auto& d: dir) {
                    auto di = elem.first + d[0];
                    auto dj = elem.second + d[1];
                    if (0 <= di && di < n && 0 <= dj && dj < n && seen[di][dj] == -1) {
                        q_back.push_back({di, dj});
                        seen[di][dj] = 0;
                    }
                }
            }
            if (q_back.empty())
                break;
            ++ret;
            swap(q, q_back);
        }

        return ret;
    }
};