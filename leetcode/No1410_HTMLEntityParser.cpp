# include <string>
# include <vector>
# include <algorithm>
# include <unordered_map>

using namespace std;

class Solution {
public:
    string entityParser(string text) {

        unordered_map<string, string> m = {
            {"&quot;", "\""},
            {"&apos;", "\'"},
            {"&amp;", "&"},
            {"&gt;", ">"},
            {"&lt;", "<"},
            {"&frasl;", "/"},
        };     

        string res = "", tmp;
        for (int i = 0; i < text.length();) {
            if (text[i] == '&') {
                tmp = "&";
                ++i;
                while ((i < text.length()) && (text[i] != ';') && (text[i] != '&')) {
                    tmp.push_back(text[i++]);
                }
                
                if (i < text.length() && text[i] == ';') {
                    tmp.push_back(text[i++]);
                }                
                
                res.append(m.find(tmp) != m.end() ? m[tmp]: tmp);  

            } else {
                res.push_back(text[i++]);
            }
        }
        
        return res;
    }
};
