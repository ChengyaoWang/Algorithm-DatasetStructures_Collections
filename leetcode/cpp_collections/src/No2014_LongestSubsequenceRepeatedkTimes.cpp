# include <string>
# include <vector>
# include <functional>
# include <algorithm>
# include <unordered_map>
using namespace std;

class Solution {
private:
    string ret, s;
    int k;
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        // Some preparation
        this -> ret = "";
        this -> s = s;
        this -> k = k;
        vector<char> candi_c = {};
        unordered_map<char, int> c2i = {};
        for (auto c: s) {
            if (++c2i[c] == k) {
                c2i[c] = 0;
                candi_c.push_back(c);
            }
        }
        sort(candi_c.begin(), candi_c.end(), greater<char>());
        dfs(candi_c, 0, string() = {});

        return ret;
    }

    bool isSubstr(string substr) {
        int i = 0, n = substr.size(), l = substr.size() * k;
        for (auto c: s) {
            if (substr[i % n] == c)     ++i;
            if (i == l)     return true;
        }
        return false;
    }

    void dfs(vector<char>& candi_c, int mask, string& sofar) {
        if (mask == (1 << candi_c.size()) - 1 || candi_c.size() == 0) {
            return;
        }

        for (int i = 0; i < candi_c.size(); ++i) {
            if ((mask >> i) % 2)    continue;
            mask |= (1 << i);
            sofar.push_back(candi_c[i]);
            if (isSubstr(sofar)) {
                if (sofar.size() > ret.size()) {
                    ret = sofar;
                }
                dfs(candi_c, mask, sofar);
            }
            sofar.pop_back();
            mask ^= (1 << i);
        }
        return;
    }

};