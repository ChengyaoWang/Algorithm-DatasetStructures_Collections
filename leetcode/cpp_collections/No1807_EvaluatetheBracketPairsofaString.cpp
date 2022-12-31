# include <vector>
# include <string>
# include <unordered_map>
using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> replace = {};
        for (auto p: knowledge) 
            replace[p[0]] = p[1];

        string ret = "", buffer = "";
        bool inBacket = false;
        for (auto c: s) {
            
            if (c == '(' && !inBacket) {
                inBacket = true;
            } else if (c == ')' && inBacket) {
                inBacket = false;
                if (replace.find(buffer) == replace.end())
                    ret.push_back('?');
                else
                    ret.append(replace[buffer]);
                buffer.clear();
            } else {
                if (inBacket)
                    buffer.push_back(c);
                else
                    ret.push_back(c);
            }
        }
        return ret;
    }
};