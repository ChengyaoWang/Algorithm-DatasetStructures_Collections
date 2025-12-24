# include <vector>
using namespace std;

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        vector<int> color(n, -1);
        vector<vector<int>> nei(n, vector<int>());
        for (auto& p: dislikes) {
            nei[p[0] - 1].push_back(p[1] - 1);
            nei[p[1] - 1].push_back(p[0] - 1);
        }

        for (int i = 0; i < n; ++i) {
            if (color[i] != -1) {
                continue;
            }
            if (!dfs(i, 0, color, nei)) {
                return false;
            }
        }
        return true;
    }

    bool dfs(int node, int prev_color,
        vector<int> &color,
        vector<vector<int>> &nei
    ) {
        if (color[node] != -1) {
            return color[node] != prev_color;
        }

        color[node] = 1 - prev_color;
        for (auto& elem: nei[node]) {
            if (!dfs(elem, 1 - prev_color, color, nei))
                return false;
        }
        return true;
    }

};