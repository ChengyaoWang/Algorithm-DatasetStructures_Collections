# include <string>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        auto sp = s.rbegin(), tp = t.rbegin();
        int s_adv = 0, t_adv = 0;

        while (true) {
            while (sp != s.rend() && (s_adv > 0 || *sp == '#')) {
                s_adv += (*sp == '#') ? 1: -1;
                ++sp;
            }
            while (tp != t.rend() && (t_adv > 0 || *tp == '#')) {
                t_adv += (*tp == '#') ? 1: -1;
                ++tp;
            }
            
            if (sp != s.rend() && tp != t.rend() && *sp == *tp) {
                ++sp;
                ++tp;
            } else {
                break;
            }
            
        }
        return (sp == s.rend()) && (tp == t.rend());
    }
};