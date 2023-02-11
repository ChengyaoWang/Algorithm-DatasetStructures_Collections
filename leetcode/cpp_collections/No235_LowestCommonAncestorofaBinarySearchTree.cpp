struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto minElem = min(p -> val, q -> val);
        auto maxElem = max(p -> val, q -> val);
        if (minElem <= root -> val && root -> val <= maxElem) {
            return root;
        }

        return root -> val < minElem ?
            lowestCommonAncestor(root -> right, p, q): 
            lowestCommonAncestor(root -> left, p, q);
    }
};