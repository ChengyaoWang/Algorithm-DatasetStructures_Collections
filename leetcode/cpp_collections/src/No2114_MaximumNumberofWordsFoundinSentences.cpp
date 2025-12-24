# include <vector>
# include <string>
# include <numeric>
using namespace std;

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ret = 0;
        for (auto& s: sentences) {
            auto tmp = accumulate(
                s.begin(), s.end(), 0,
                [&](int& cumCnt, char s) {
                    return cumCnt + (s == ' ');
                }
            );
            ret = max(ret, tmp);
        }
        return ret;
    }
};