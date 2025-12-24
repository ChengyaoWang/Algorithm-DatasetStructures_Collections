# include <stack>
# include <vector>
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
    TreeNode* balanceBST(TreeNode* root) {

        vector<TreeNode*> ser = {};
        
        // Serialize BST
        TreeNode *p = root, *pp;
        stack<TreeNode*> q = {};
        while (!q.empty() || p) {
            if (p) {
                q.push(p);
                p = p -> left;
            } else {
                pp = q.top();
                q.pop();
                ser.push_back(pp);
                p = pp -> right;
            }
        }

        // Reconstruct
        return reconst(0, ser.size(), ser);
    }

    TreeNode* reconst(int l, int r, vector<TreeNode*> lst) {
        if (l == r)     return nullptr;
        auto mid = (l + r) / 2;
        lst[mid] -> left = reconst(l, mid, lst);
        lst[mid] -> right = reconst(mid + 1, r, lst);
        return lst[mid];
    }

};