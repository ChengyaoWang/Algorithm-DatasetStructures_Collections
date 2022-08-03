# include <vector>
# include <algorithm>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {

public:
    vector<int> postorder(Node* root) {
        vector<int> retList;
        _helper(root, retList);
        return retList;
    }


    void _helper(Node* ptr, vector<int>& res) {
        if (ptr == nullptr) {
            return ;
        }
        for (auto &i: ptr -> children) {
            _helper(i, res);
        }
        res.push_back(ptr -> val);
        return ;
    }
};