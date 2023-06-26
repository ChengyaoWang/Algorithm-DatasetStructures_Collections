# include <vector>
# include <string>
using namespace std;

class Trie {
public:
    int idx;
    vector<Trie*> t;

    Trie(int idx = -1) {
        this -> idx = idx;
        this -> t = vector<Trie*>(26);
    }
    void Insert(int depth, string& src, int index) {
        if (depth == src.size()) {
            idx = index;
            return;
        }

        auto i = src[depth] - 'a';
        if (t[i] == nullptr) {
            t[i] = new Trie();
        }
        t[i] -> Insert(depth + 1, src, index);
        return;
    }

    int findStr(int depth, string& src) {
        if (idx != -1 || depth == src.size()) {
            return idx;
        } 
        auto next = t[src[depth] - 'a'];
        if (next == nullptr) {
            return -1;
        }
        return next -> findStr(depth + 1, src);
    }

};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        
        Trie *t = new Trie();
        for (int i = 0; i < dictionary.size(); ++i) {
            t -> Insert(0, dictionary[i], i);
        }

        string ret = "";
        size_t s = 0, e = sentence.find_first_of(' ');
        for (;;) {
            auto substr = sentence.substr(s, e - s);
            auto i = t -> findStr(0, substr);
            if (i != -1) {
                substr = dictionary[i];
            }
            ret.append(substr + " ");
            if (e == string::npos) {
                break;
            }
            s = e + 1;
            e = sentence.find_first_of(' ', s);
        }

        ret.pop_back();
        return ret;
    }
};