# include <string>
# include <vector>
using namespace std;

struct elem {
    char c;
    int reps;
    elem(char c): c(c), reps(1) {}
};

class Solution {
public:
    int maxRepOpt1(string text) {

        int ret = 1;
        vector<elem> enc;
        vector<int> totalCnt(26);
        for (auto& c: text) {
            if (!enc.empty() && enc.back().c == c) {
                ret = max(ret, ++enc.back().reps);
            } else {
                enc.emplace_back(c);
            }
            ++totalCnt[c - 'a'];
        }

        for (int i = 0; i < enc.size(); ++i) {
            
            if (enc[i].reps < totalCnt[enc[i].c - 'a']) {
                ret = max(ret, enc[i].reps + 1);
            }

            if (
                (1 <= i && i < (enc.size() - 1)) &&
                (enc[i].reps == 1) &&
                (enc[i - 1].c == enc[i + 1].c)
            ) {
                auto lrSum = enc[i - 1].reps + enc[i + 1].reps;
                ret = max(ret, lrSum + (lrSum < totalCnt[enc[i - 1].c - 'a']));
            }
        }

        return ret;
    }
};