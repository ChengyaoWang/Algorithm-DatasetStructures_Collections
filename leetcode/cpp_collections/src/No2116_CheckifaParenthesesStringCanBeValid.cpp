# include <string>
# include <algorithm>

using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.length() % 2 == 1) {
            return false;
        }

        int gap = 0, unlocked_cnt = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (locked[i] == '0') {
                ++unlocked_cnt;
            } else {
                gap += (s[i] == ')') ? 1: -1;
            }
            if (unlocked_cnt < gap) return false;
        }
        
        gap = 0;
        unlocked_cnt = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            if (locked[i] == '0') {
                ++unlocked_cnt;
            } else {
                gap += (s[i] == '(') ? 1: -1;
            }
            if (unlocked_cnt < gap) return false;
        }
        return true;
    }
};