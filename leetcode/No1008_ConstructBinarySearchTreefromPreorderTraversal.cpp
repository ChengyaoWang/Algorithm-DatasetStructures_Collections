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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<TreeNode*> s = {};
        TreeNode* p = new TreeNode(1001);
        s.push_back(p);

        for (auto &i: preorder) {
            if (i < s.back() -> val) {
                s.back() -> left = new TreeNode(i);
                s.push_back(s.back() -> left);
            } else {
                while (i > s.back() -> val) {
                    p = s.back();
                    s.pop_back();
                }
                p -> right = new TreeNode(i);
                s.push_back(p -> right);
            }
        }

        return s.front() -> left;
    }
};