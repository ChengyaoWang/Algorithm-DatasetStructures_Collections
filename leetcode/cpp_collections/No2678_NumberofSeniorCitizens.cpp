# include <vector>
# include <string>
using namespace std;

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ret = 0;
        for (auto& s: details) {
            ret += (s[11] >= '7') | (s[11] == '6' && s[12] > '0');
        }
        return ret;
    }
};
