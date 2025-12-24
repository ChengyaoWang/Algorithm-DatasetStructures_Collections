# include <numeric>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void dfs(TreeNode* p, int& opt, int& prev) {
        if (p == nullptr) {
            return ;
        }

        dfs(p -> left, opt, prev);
        opt = min(opt, abs(p -> val - prev));
        prev = p -> val;
        dfs(p -> right, opt, prev);

        return ;
    }

    int getMinimumDifference(TreeNode* root) {
        
        auto opt = 200000, prev = -200000;
        dfs(root, opt, prev);
        return opt;
    }
};