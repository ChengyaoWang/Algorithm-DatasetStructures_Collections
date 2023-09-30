# include <queue>
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
    TreeNode* reverseOddLevels(TreeNode* root) {
        deque<TreeNode*> q = {root}, q_tmp;
        int lvl = 0;
        
        while (!q.empty()) {
            // Generate the Next Level
            q_tmp.clear();
            while (!q.empty()) {
                auto elem = q.front();
                q.pop_front();
                if (elem -> left)
                    q_tmp.push_back(elem -> left);
                if (elem -> right)
                    q_tmp.push_back(elem -> right);
            }
            q = q_tmp;
            if (!q_tmp.empty() && ((lvl & 1) == 0)) {
                while (!q_tmp.empty()) {
                    auto f = q_tmp.front();
                    auto b = q_tmp.back();
                    q_tmp.pop_front();
                    q_tmp.pop_back();
                    swap(f -> val, b -> val);
                }
            }
            ++lvl;
        }
        return root;
    }
};