# include <vector>
# include <unordered_map>
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        unordered_map<int, pair<TreeNode*, bool>> m;

        for (auto& row: descriptions) {
            if (m.find(row[0]) == m.end()) {
                auto p = new TreeNode(row[0]);
                m[row[0]] = {p, false};
            }
            if (m.find(row[1]) == m.end()) {
                auto p = new TreeNode(row[1]);
                m[row[1]] = {p, true};
            } else {
                m[row[1]].second |= true;
            }

            if (row[2] == 1) {
                m[row[0]].first -> left = m[row[1]].first;
            } else {
                m[row[0]].first -> right = m[row[1]].first;
            }
        }

        for (auto& [v, p]: m) {
            if (!p.second)
                return p.first;
        }
        return nullptr;
    }
};