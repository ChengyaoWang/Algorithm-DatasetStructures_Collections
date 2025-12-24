# include <vector>
using namespace std;

class Solution {
public:
    void dfs(
        int node, vector<int>& pathSoFar,
        vector<vector<int>>& graph, vector<vector<int>> &ret
    ) {
        if (node == graph.size() - 1) {
            vector<int> cpyPath(pathSoFar.size());
            copy(pathSoFar.begin(), pathSoFar.end(), cpyPath.begin());
            cpyPath.push_back(node);
            ret.push_back(cpyPath);
            return ;
        }

        for (auto& nei: graph[node]) {
            pathSoFar.push_back(node);
            dfs(nei, pathSoFar, graph, ret);
            pathSoFar.pop_back();
        }

        return ;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> pathSoFar;
        vector<vector<int>> ret;
        dfs(0, pathSoFar, graph, ret);
        return ret;
    }
};