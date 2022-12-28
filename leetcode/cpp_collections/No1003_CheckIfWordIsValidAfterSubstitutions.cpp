# include <string>
# include <vector>

using namespace std;

class Solution {
public:
    bool isValid(string s) {

        vector<char> s = {};
        for (auto &c: s) {
            if (
                c == 'c' && 
                s.size() > 2 &&
                (s[s.size() - 1] == 'b') && 
                (s[s.size() - 2] == 'a')
            ) {
                s.pop_back();
                s.pop_back();
            } else {
                s.push_back(c);
            }
        }

        return s.empty();        
    }
};