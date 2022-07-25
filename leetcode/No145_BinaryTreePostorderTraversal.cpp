# include <vector>
# include <algorithm>

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
    vector<int> postorderTraversal(TreeNode* root) {

        // Recursion is Trivial, Use Iteration
        vector<int> retList;
        vector<TreeNode*> stack;
        
        TreeNode *p = root, *pp = nullptr;
        while (stack.empty() || p != nullptr) {
            if (p != nullptr) {
                retList.push_back(p -> val);
                stack.push_back(p);
                p = p -> right;
            } else {
                pp = stack.back();
                stack.pop_back();
                retList.pop_back();
                p = pp -> left;
            }
        }

        reverse(retList.begin(), retList.end());
        return retList;
    }
};