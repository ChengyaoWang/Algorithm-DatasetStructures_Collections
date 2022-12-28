# include <vector>
# include <queue>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n);
        deque<int> q = {};

        for (int i = 0; i < n; ++i) {
            if (color[i] != 0)
                continue;
            color[i] = 1;
            q.push_back(i);
            while (!q.empty()) {
                auto tmp = q.front();
                q.pop_front();
                for (auto l: graph[tmp]) {
                    if (color[l] == color[tmp]) return false;
                    if (color[l] == 0) {
                        color[l] = -color[tmp];
                        q.push_back(l);
                    }
                }
            }
        }
        return true;
    }
};