# include <string>
using namespace std;

class Solution {
public:
    int longestContinuousSubstring(string s) {
        
        int cnt = 0, opt = 0;
        for (int i = 0; i < s.size() - 1; ++i) {
            cnt = (s[i + 1] - s[i] == 1) ? cnt + 1: 0;
            opt = max(opt, cnt);            
        }

        return opt + 1;
    }
};