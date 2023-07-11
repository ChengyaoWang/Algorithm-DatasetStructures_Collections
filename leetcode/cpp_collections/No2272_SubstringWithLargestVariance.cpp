# include <string>
# include <unordered_set>
using namespace std;

class Solution {
public:
    int getMax(char a, char b, string& s) {
        int iN = 0, iP = 0;
        int sofarN = 0, sofarP = 0, cumSum = 0;
        for (int i = 0, ii = 0; i < s.size(); ++i) {
            char c = s[i];
            if (c != a && c != b) {
                continue;
            }
            ++ii;
            sofarN += ((c == a) ? -1: 1);
            sofarP += ((c == b) ? -1: 1);
            if (sofarN < 0) {
                sofarN = 0;
                iN = ii;
            }
            if (sofarP < 0) {
                sofarP = 0;
                iP = ii;
            }
            cumSum = max(cumSum, max(
                (ii - iN == sofarN) ? 0: sofarN,
                (ii - iP == sofarP) ? 0: sofarP
            ));

        }
        return cumSum;
    }

    int largestVariance(string s) {

        string sRev = s;
        reverse(sRev.begin(), sRev.end());
        unordered_set<char> mem(s.begin(), s.end());
        
        int maxCnt = 0;
        for (auto it = mem.begin(); it != mem.end(); ++it) {
            for (auto jt = next(it); jt != mem.end(); ++jt) {
                maxCnt = max(maxCnt, getMax(*it, *jt, s));
                maxCnt = max(maxCnt, getMax(*it, *jt, sRev));
            }
        }

        return maxCnt;
    }
};