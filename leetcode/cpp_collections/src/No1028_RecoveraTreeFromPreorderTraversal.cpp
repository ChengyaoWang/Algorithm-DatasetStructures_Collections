# include <vector>
# include <string>
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
    void parse(string& traversal, vector<pair<int, int>>& res) {
        res.emplace_back(0, 0);
        char prevChar = '\0';
        for (auto& c: traversal) {
            if (c == '-') {
                if (isdigit(prevChar)) {
                    res.emplace_back(0, 0);
                }
                ++res.back().first;
            } else {
                res.back().second *= 10;
                res.back().second += (c - '0');
            }
            prevChar = c;
        }
    }

    TreeNode* recoverFromPreorder(string traversal) {

        vector<pair<int, int>> parseResult = {};
        parse(traversal, parseResult);

        vector<TreeNode*> stack = {};
        for (auto& p: parseResult) {
            while(p.first < stack.size()) {
                stack.pop_back();
            }
            auto tmp = new TreeNode(p.second);
            if (!stack.empty()) {
                if (stack.back() -> left) {
                    stack.back() -> right = tmp;
                } else {
                    stack.back() -> left = tmp;
                }
            }
            stack.push_back(tmp);
        }

        return stack[0];
    }
};