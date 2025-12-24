# include <vector>
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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {

        queue<int> q1, q2;
        serialize(root1, q1);
        serialize(root2, q2);

        int elem;
        vector<int> ret;
        while (!q1.empty() || !q2.empty()) {
            if (!q1.empty() && (q2.empty() || q1.front() < q2.front())) {
                elem = q1.front();
                q1.pop();
            } else {
                elem = q2.front();
                q2.pop();
            }
            ret.push_back(elem);
        }
        return ret;
    }

    void serialize(TreeNode* p, queue<int>& ret) {
        
        vector<TreeNode*> s;
        TreeNode* pp = nullptr;
        while (!s.empty() || p != nullptr) {
            if (p != nullptr) {
                s.push_back(p);
                p = p -> left;
            } else {
                pp = s.back();
                s.pop_back();
                ret.push(pp -> val);
                p = pp -> right;
            }
        }
    }
};