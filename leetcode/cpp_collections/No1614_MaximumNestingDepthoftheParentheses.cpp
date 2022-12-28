# include <string>

using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int l = 0, res = 0;

        for (auto &i: s) {
            if (i == '(') {
                ++l;
            } else if (i == ')') {
                --l;
            } else {
                res = max(res, l);
            }
        }
        return l;
    }
};