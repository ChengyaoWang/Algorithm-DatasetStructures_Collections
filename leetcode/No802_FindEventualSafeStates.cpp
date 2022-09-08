# include <vector>

using namespace std;

class Solution {
private:
    vector<int> isSafe;
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        isSafe = vector<int>(graph.size(), 0);

        for (int i = 0; i < graph.size(); ++i) {
            helper(i, &graph);
        }

        vector<int> res = {};
        for (int i = 0; i < graph.size(); ++i) {
            if (isSafe[i] == 1)  res.push_back(i);
        }
        return res;
    }

    int helper(int node, vector<vector<int>> *graph) {
        if (isSafe[node] != 0) {
            return isSafe[node];
        }
        
        isSafe[node] = (*graph)[node].size() == 0 ? 1: 2;
        bool res = true;
        for (auto i: (*graph)[node]) {
            res &= (helper(i, graph) == 1);
        }
        isSafe[node] = res ? 1: 2;

        return isSafe[node];
    }
};