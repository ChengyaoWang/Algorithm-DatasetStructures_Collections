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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {

        if (root == nullptr) {
            auto t = new TreeNode(val);
            return t;
        } else if (val > root -> val) {
            auto t = new TreeNode(val, root, nullptr);
            return t;
        }

        root -> right = insertIntoMaxTree(root -> right, val);
        return root;
    }
};
