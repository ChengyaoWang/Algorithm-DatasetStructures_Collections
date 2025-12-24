# include <string>
# include <vector>
using namespace std;

class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> ret;
        auto lo_col = s[0], hi_col = s[3];
        auto lo_row = s[1], hi_row = s[4];

        for (auto cj = lo_col; cj <= hi_col; ++cj) {
            for (auto ci = lo_row; ci <= hi_row; ++ci) {
                ret.push_back(string{cj, ci});
            }

        }

        return ret;
    }
};