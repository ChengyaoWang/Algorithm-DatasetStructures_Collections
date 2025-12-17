# include <limits>
# include <string>
# include <vector>
# include <set>

using namespace std;

class TrieNode {
public:
vector<TrieNode*> children;
bool isWord;
    TrieNode() {
        this -> children = vector<TrieNode*>(26, NULL);
        this -> isWord = false;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }

    void insert(string s) {
        TrieNode* p = root;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if ((*p).children[c - 'a'] == NULL) {
                TrieNode* tmp = new TrieNode();
                (*p).children[c - 'a'] = tmp;
            }
            p = (*p).children[c - 'a'];
        }
        (*p).isWord = true;
    }

    vector<int> tracePath(string s) {
        TrieNode *p = root;
        vector<int> ret;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            p = (*p).children[c - 'a'];
            if (p == nullptr)
                break;
            else if (p -> isWord)
                ret.push_back(i + 1);
        }
        return ret;
    }
};

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {

        vector<int> dp(s.size() + 1, numeric_limits<int>::max());
        dp[0] = 0;

        Trie tree;
        for (auto &subS: dictionary)
            tree.insert(subS);

        for (int i = 0; i < dp.size(); ++i) {
            if (i != 0)
                dp[i] = min(dp[i - 1] + 1, dp[i]);

            string subS = s.substr(i, s.size() - i + 1);
            vector<int> subIdx = tree.tracePath(subS);
            for (auto &l: subIdx)
                dp[i + l] = min(dp[i + l], dp[i]);
        }

        return dp.back();
    }
};