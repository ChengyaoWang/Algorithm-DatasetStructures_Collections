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
    void flatten(TreeNode* root) {
        helper(root);
        return;
    }

    TreeNode* helper(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        
        auto l = helper(root -> left);
        auto r = helper(root -> right);

        if (l != nullptr) {
            l -> right = root -> right;
            root -> right = root -> left;
            root -> left = nullptr;
        }

        if (r != nullptr) {
            return r;
        } else if (l != nullptr) {
            return l;
        } else {
            return root;
        }
    }
};