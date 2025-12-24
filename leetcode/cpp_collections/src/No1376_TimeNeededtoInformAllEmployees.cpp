# include <vector>
using namespace std;

class Solution {
private:
    int dfs(int i, vector<int> &manager, vector<int> &informTime, vector<int> &depth) {
        if (manager[i] == -1) {
            return 0;
        } else if (depth[i] != -1) {
            return depth[i];
        }
        depth[i] = informTime[manager[i]] + dfs(manager[i], manager, informTime, depth);
        return depth[i];
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int res = 0;
        vector<int> depth(n, -1);
        for (int i = 0; i < n; ++i) {
            res = max(res, dfs(i, manager, informTime, depth));
        }
        return res;        
    }
};