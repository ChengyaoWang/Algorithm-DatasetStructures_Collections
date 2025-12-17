# include <set>
# include <map>
# include <limits>
# include <vector>

using namespace std;

class Solution {
public:
    int dfs(
        int i, int th, vector<int>& mem,
        unordered_map<int, vector<pair<int, int>>>& edge_map
    ) {
        mem[i] = 1;
        int node_visited = 1;

        for (auto& nei: edge_map[i]) {
            if (nei.second > th)
                continue;
            if (mem[nei.first] == 1)
                continue;
            node_visited += dfs(nei.first, th, mem, edge_map);
        }

        return node_visited;
    }

    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {

        int edge_max = numeric_limits<int>::min();
        unordered_map<int, vector<pair<int, int>>> edge_map;
        for (auto &e: edges) {
            edge_map[e[1]].push_back(make_pair(e[0], e[2]));
            edge_max = max(edge_max, e[2]);
        }

        vector<int> mem(n, 0);
        int lo = 1, hi = edge_max + 1, mid;

        while(lo < hi) {
            mid = (lo + hi) / 2;

            int max_node_visited = dfs(0, mid, mem, edge_map);
            if (max_node_visited == n) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
            fill_n(mem.begin(), mem.size(), 0);
        }

        return lo == edge_max + 1 ? -1: lo;
    }
};