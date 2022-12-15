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
    // Using Recursion Methods is easy, try iterative method
    vector<int> largestValues(TreeNode* root) {
        vector<pair<TreeNode*, int>> stack = {};
        if (root)   stack.push_back({root, 0});
        vector<int> res = {};
        while (!stack.empty()) {
            auto tmp = stack.back();
            stack.pop_back();

            if (res.size() < tmp.second + 1) {
                res.resize(tmp.second + 1);
                res[tmp.second] = tmp.first -> val;
            } else {
                res[tmp.second] = max(res[tmp.second], tmp.first -> val);
            }

            if (tmp.first -> left)  stack.push_back({tmp.first -> left, tmp.second + 1});
            if (tmp.first -> right) stack.push_back({tmp.first -> right, tmp.second + 1});
        }

        return res;
    }
};