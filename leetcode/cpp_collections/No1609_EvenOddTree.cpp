struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

# include <queue>
# include <numeric>
using namespace std;

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q1, q2;
        q1.push(root);
        int level = 0;
        while (!q1.empty()) {
            auto p = (level % 2 == 0) ? 
                numeric_limits<int>::min() :
                numeric_limits<int>::max();
            while (!q1.empty()) {
                auto elem = q1.front();
                q1.pop();
                if (elem -> val == p)
                    return false;
                if ((elem -> val <= p) xor (level & 1 == 1))
                    return false;
                if ((elem -> val % 2 == 0) xor (level % 2 == 1))
                    return false;
                p = elem -> val;
                if (elem -> left)   q2.push(elem -> left);
                if (elem -> right)  q2.push(elem -> right);
            }
            swap(q1, q2);
            ++level;
        }

        return true;
    }
};