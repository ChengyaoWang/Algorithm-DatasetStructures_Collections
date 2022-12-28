# include <vector>
# include <stack>
using namespace std;

// vector<int> invTree(n, -1);
// for (auto &i: edges) {
//     invTree[i[1]] = i[0];
// }
// vector<int> cumSteps(n);
// for (int i = n - 1; i >= 0; --i) {
//     if (invTree[i] == -1)   continue;
//     if (hasApple[i]) {
//         cumSteps[invTree[i]] += cumSteps[i] + 2;
//         hasApple[invTree[i]] = true;
//     }
// }

// return cumSteps[0];

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> tree(n, vector<int> {});
        for (auto &i: edges) {
            tree[i[0]].push_back(i[1]);
            tree[i[1]].push_back(i[0]);
        }
        vector<bool> seen(n, false);
        return dfsHelper(0, tree, hasApple, seen).first;
    }

    pair<int, bool> dfsHelper(int n, vector<vector<int>>& tree, vector<bool>& hasApple, vector<bool>& seen) {

        seen[n] = true;

        int cnt = 0;
        bool a = false;
        for (auto &i: tree[n]) {
            if (seen[i])    continue;
            auto res = dfsHelper(i, tree, hasApple, seen);
            cnt += res.first + 2 * int(res.second);
            a |= res.second;
        }
        
        return {cnt, a | hasApple[n]};
    }
};