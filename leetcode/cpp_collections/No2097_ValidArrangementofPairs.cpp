# include <vector>
# include <unordered_map>
using namespace std;

class Solution {
public:

    int buildGraph(
        vector<vector<int>>& pairs,
        unordered_map<int, vector<int>>& graph
    )
    {
        unordered_map<int, int> degree;
        for (auto& p: pairs) {
            auto a = p[0], b = p[1];
            graph[a].push_back(b);
            --degree[b];
            ++degree[a];
        }
        for (auto& [k, v]: degree) {
            if (v == 1)
                return k;
        }
        return graph.begin() -> first;
    }

    void dfs(
        int node,
        unordered_map<int, vector<int>>& graph,
        vector<vector<int>>& ret
    )
    {
        auto& a = graph[node];
        while (!a.empty()) {
            auto nei = a.back();
            a.pop_back();
            dfs(nei, graph, ret);
            ret.push_back({node, nei});
        }
    }

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {

        unordered_map<int, vector<int>> graph;
        int st = buildGraph(pairs, graph);
        vector<vector<int>> ret;
        
        dfs(st, graph, ret);
        reverse(ret.begin(), ret.end());
        
        return ret;
    }
};