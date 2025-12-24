# include <string>
# include <vector>
# include <numeric>
using namespace std;

class Solution {
public:
    int findSubstringInWraproundString(string s) {

        vector<int> mem(26);
        
        int l = 1;
        int prevChar = s[0] - 'a';
        for (auto& i: s) {
            int curChar = i - 'a';
            if ((prevChar + 1) % 26 == curChar) {
                ++l;
            } else {
                l = 1;
            }
            mem[curChar] = max(mem[curChar], l);
            prevChar = curChar;
        }

        return accumulate(mem.begin(), mem.end(), 0);
    }
};