# include <vector>
using namespace std;

class TreeAncestor {
public:
    vector<vector<int>> dp;
    TreeAncestor(int n, vector<int>& parent) {
        dp = vector<vector<int>>(n, vector<int>(20));
        for (int i = 0; i < n; ++i) {
            dp[i][0] = parent[i];
        }
        for (int i = 1; i < 20; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[j][i - 1] == -1) {
                    dp[j][i] = -1;
                } else {
                    dp[j][i] = dp[dp[j][i - 1]][i - 1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int i = 0; i < 20; i++) {
            if (k & (1 << i)) {
                node = dp[node][i];
                if (node == -1) return -1;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */