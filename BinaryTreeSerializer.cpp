/*
    Serialization & Deserialization of Binary Trees
        https://leetcode.com/problems/serialize-and-deserialize-binary-tree/  
*/
# include <string>
# include <deque>

using namespace std;

// TreeNode Definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Solution Class
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string retStr = "";
        deque<TreeNode*> q = {root};
        TreeNode* p = nullptr;
        int nullCnt = (root == nullptr);
        
        while(q.size() > nullCnt){
            p = q.front();
            q.pop_front();
            if(p == nullptr){
                retStr.append("N,");
                --nullCnt;
            }
            else{
                retStr.append(to_string(p -> val) + ",");
                q.push_back(p -> left);
                q.push_back(p -> right);
                if(p -> left == nullptr)
                    ++nullCnt;
                if(p -> right == nullptr)
                    ++nullCnt;
            }
        }
        return retStr;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = nullptr;
        TreeNode* p = nullptr;
        deque<TreeNode*> q = {};
        string buf = "";
        bool isLeft = true;
        for(auto& c: data){
            if(c == ','){
                p = (buf != "N") ? new TreeNode(stoi(buf)): nullptr;
                if(root == nullptr)
                    root = p;
                else{
                    if(isLeft){
                        q.front() -> left = p;
                        isLeft = false;
                    }
                    else{
                        q.front() -> right = p;
                        q.pop_front();
                        isLeft = true;
                    }
                }
                if(p)       q.push_back(p);
                buf.clear();
                continue;
            }
            buf.push_back(c);
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));