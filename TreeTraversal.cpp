# include <vector>
# include <deque>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val) {val = _val;}
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode() {}
    TreeNode(int _val) {val = _val;}
    TreeNode(int _val, TreeNode* l, TreeNode* r) {
        val = _val;
        left = l;
        right = r;
    }
};


class Solution {

public:
    vector<int> preorder(Node* root) {
        vector<int> retList;
        vector<pair<Node*, int>> s;
        pair<Node*, int> p = {root, 0}, pp;

        while (!s.empty() || (p.first) != nullptr) {
            if (p.first != nullptr) {
                retList.push_back(p.first -> val);
                s.push_back(p);
                p = {
                    (p.first -> children).size() == 0 ? nullptr: (p.first -> children)[0],
                    0
                };
            } else {
                pp = s.back();
                s.pop_back();
                ++pp.second;
                if (pp.second < (pp.first -> children).size()) {
                    p = {(pp.first -> children)[pp.second], 0};
                    s.push_back(pp);
                }
            }
        }
        return retList;
    }

    vector<int> postorder(Node* root) {
        vector<int> retList;
        vector<pair<Node*, int>> s;
        pair<Node*, int> p = {root, 0}, pp;

        while (!s.empty() || (p.first) != nullptr) {
            if (p.first != nullptr) {
                s.push_back(p);
                p = {
                    (p.first -> children).size() == 0 ? nullptr: (p.first -> children)[0],
                    0
                };
            } else {
                pp = s.back();
                s.pop_back();
                ++pp.second;
                if (pp.second < (pp.first -> children).size()) {
                    p = {(pp.first -> children)[pp.second], 0};
                    s.push_back(pp);
                } else {
                    p = {nullptr, 0};
                    retList.push_back(pp.first -> val);
                }
            }
        }
        return retList;
    }

    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) {
            return {};
        }
        vector<vector<int>> retList;
        deque<Node*> q = {root};
        Node* p = nullptr;
        int N = -1;

        while (!q.empty()) {
            N = q.size();
            vector<int> lvl;
            for (int i = 0; i < N; ++i) {
                p = q.front();
                q.pop_front();
                lvl.push_back(p -> val);
                for (auto &i: p -> children) {
                    q.push_back(i);
                }
            }
            retList.push_back(lvl);
        }

        return retList;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<TreeNode*> s;
        vector<int> retList;
        TreeNode *p = root, *pp = nullptr;

        while (!s.empty() || p != nullptr) {

            if (p != nullptr) {
                s.push_back(p);
                retList.push_back(p -> val);
                p = p -> left;
            } else {
                p = s.back() -> right;
                s.pop_back();
            }         

        }
        return retList;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<TreeNode*> s;
        vector<int> retList;
        TreeNode *p = root, *pp = nullptr;
        
        while (!s.empty() || p != nullptr) {

            if (p != nullptr) {
                s.push_back(p);
                p = p -> left;
            } else {
                pp = s.back();
                s.pop_back();
                retList.push_back(pp -> val);
                p = pp -> right;
            }

        }

        return retList;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<TreeNode*> s;
        vector<int> retList;
        TreeNode *p = root, *pp = nullptr, *last = nullptr;
        
        while (!s.empty() || p != nullptr) {

            if (p != nullptr) {
                s.push_back(p);
                p = p -> left;
            } else {
                pp = s.back();

                if (pp -> right == nullptr || pp -> right == last) {
                    retList.push_back(pp -> val);
                    s.pop_back();
                    last = pp;
                    p = nullptr;
                } else {
                    p = p -> right;
                }
            }

        }

        return retList;
    }

};