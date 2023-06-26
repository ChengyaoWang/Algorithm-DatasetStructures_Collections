# include <utility>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using namespace std;

class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int ret = 0;
        dfsHelper(root, ret);
        return ret;
    }

    pair<int, int> dfsHelper(TreeNode* root, int& ret) {
        if (root == nullptr) {
            return make_pair(0, 0);
        }

        auto pl = dfsHelper(root -> left, ret);
        auto pr = dfsHelper(root -> right, ret);

        ret += abs(pl.first - pl.second);
        ret += abs(pr.first - pr.second);

        return make_pair(
            pl.first + pr.first + 1,
            pl.second + pr.second + root -> val
        );
    }
};