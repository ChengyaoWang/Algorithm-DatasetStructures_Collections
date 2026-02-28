# include <queue>
# include <vector>
# include <string>
using namespace std;

class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        
        // Need to build a tree from edges
        vector<vector<int>> adjMx(n);

        for (auto &e: edges) {
            adjMx[e[0]].push_back(e[1]);
            adjMx[e[1]].push_back(e[0]);
        }

        deque<int> q = {0};
        vector<vector<int>> tree(n);
        while (!q.empty()) {
            auto par = q.front();
            q.pop_front();
            for (auto &i: adjMx[par]) {
                // cout << i << "|" << par << endl;
                if (!tree[i].empty())
                    continue;
                tree[par].push_back(i);
                q.push_back(i);
            }
        }

        vector<int> ans(n, 0);
        dfs(0, ans, &tree, &labels);
        return ans;
    }

    vector<int> dfs(
        int i,
        vector<int> &ans,
        vector<vector<int>> *tree,
        string *labels
    ) {
        vector<int> ret(26, 0);

        if (!(*tree)[i].empty()) {
            for (auto &j: (*tree)[i]) {
                vector<int> tmp = dfs(j, ans, tree, labels);
                for (int k = 0; k < 26; ++k)
                    ret[k] += tmp[k];
            }
        }

        ans[i] = ++ret[(*labels)[i] - 'a'];
        return ret;
    }
};