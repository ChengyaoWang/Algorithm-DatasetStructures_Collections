# include <map>
# include <vector>
# include <string>
# include <unordered_map>
using namespace std;

struct TrieNode {
    bool flag_del;
    string c;
    TrieNode *parent;
    map<string, TrieNode*> child;

    TrieNode(): flag_del(false), c("/"), parent(nullptr), child({}) {};
    TrieNode(string c, TrieNode *p): flag_del(false), c(c), parent(p), child({}) {};

    TrieNode* CreateOrTraceDown(string c) {
        if (child.find(c) != child.end())
            return child[c];
        child[c] = new TrieNode(c, this);
        return child[c];
    }

    string EncodeSubDir(unordered_map<string, TrieNode*> &m) {
        string baseStr = "";
        for (auto [s, p]: child) {
            baseStr += (p -> EncodeSubDir(m));
        }

        if (!baseStr.empty()) {
            if (m.find(baseStr) != m.end()) {
                m[baseStr] -> flag_del = true;
                this -> flag_del = true;
            }
            m[baseStr] = this;
        }
        return c + "(" + baseStr + ")";
    }

    void Reconstruct(vector<string> path, vector<vector<string>> &res) {
        if (c != "/")
            res.push_back(path);
        for (auto [s, p]: child) {
            if (p -> flag_del)
                continue;
            path.push_back(p -> c);
            p -> Reconstruct(path, res);
            path.pop_back();
        }
    }

};

class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        // Build Directory Tree
        TrieNode *root = new TrieNode(), *tmp;
        unordered_map<string, TrieNode*> dup = {};
        for (auto& path: paths) {
            tmp = root;
            for (auto dir: path) {
                tmp = tmp -> CreateOrTraceDown(dir);
            }
        }
        // Find All Duplicates
        root -> EncodeSubDir(dup);

        // Reconstruct All Directory
        vector<string> path = {};
        vector<vector<string>> ret = {};
        root -> Reconstruct(path, ret);

        return ret;
    }
};