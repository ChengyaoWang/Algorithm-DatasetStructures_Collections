# include <string>
# include <vector>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {

        vector<bool> s;
        preorder.push_back(',');

        size_t p = 0, p_next = preorder.find(",", p);
        while (p != preorder.size()) {
            
            auto substr = preorder.substr(p, p_next - p) == "#";
            if (substr) {
                while (s.size() >= 2 && !*(s.end() - 2) && *(s.end() - 1)) {
                    s.pop_back();
                    s.pop_back();
                }
            }
            s.push_back(substr);
            p = p_next + 1;
            p_next = preorder.find(",", p);
        }

        return s.size() == 1 & s.back();
    }
};