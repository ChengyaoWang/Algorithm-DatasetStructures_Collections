# include <string>
# include <vector>
using namespace std;

class Solution {
public:
    string reformatNumber(string number) {
        
        vector<char> s = {};
        string ret = "";

        for (char c: number) {
            if (c == '-' || c == ' ') 
                continue;
            s.push_back(c);
            if (s.size() == 3) {
                ret += string(s.begin(), s.end()) + "-";
                s.clear();
            }
        }

        if (s.size() == 0)  ret.pop_back();
        else if (s.size() == 1) {
            swap(ret[ret.size() - 2], ret[ret.size() - 1]);
        }

        ret += string(s.begin(), s.end());
        return ret;        
    }
};