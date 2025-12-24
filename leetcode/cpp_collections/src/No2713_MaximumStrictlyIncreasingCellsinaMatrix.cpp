# include <queue>
# include <numeric>
# include <vector>
using namespace std;

using pi = pair<int, int>;

class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {

        int m = mat.size(), n = mat[0].size();
        auto valFunc = [&](const pi& i, const pi& j) {
            return mat[i.first][i.second] > mat[j.first][j.second];
        };

        priority_queue<pi, vector<pi>, decltype(valFunc)> pq(valFunc);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                pq.emplace(i, j);
            }
        }

        int ret = 0;
        vector<pi> row(m, pi(0, 0)), col(n, pi(0, 0));
        vector<int> rowMax(m, -100001), colMax(n, -100001);

        while (!pq.empty()) {
            auto p = pq.top();
            auto i = p.first, j = p.second;
            pq.pop();

            auto flag1 = rowMax[i] == mat[i][j];
            auto flag2 = colMax[j] == mat[i][j];
            auto v = max(
                flag1 ? row[i].first: row[i].second,
                flag2 ? col[j].first: col[j].second
            ) + 1;

            ret = max(ret, v);
            if (flag1) {
                row[i].second = max(row[i].second, v);
            } else {
                row[i] = make_pair(row[i].second, v);
            }
            if (flag2) {
                col[j].second = max(col[j].second, v);
            } else {
                col[j] = make_pair(col[j].second, v);
            }
            rowMax[i] = mat[i][j];
            colMax[j] = mat[i][j];
        };

        return ret;
    }
};