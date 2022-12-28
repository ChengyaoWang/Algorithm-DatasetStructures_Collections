# include <vector>
# include <string>
# include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> movesToStamp(string S, string T) {
        int slen = S.size(), tlen = T.size() - slen + 1, i, j;
        vector<int> ans;
        bool tdiff = true, sdiff;
        while (tdiff) {
            tdiff = false;
            for (i = 0; i < tlen; i++) {
                sdiff = false;
                for (j = 0; j < slen; j++)
                    if (T[i + j] == '*') continue;
                    else if (T[i + j] != S[j]) break;
                    else sdiff = true;
                if (j == slen && sdiff) {
                    tdiff = true;
                    fill(T.begin() + i, T.begin() + i + slen, '*');
                    ans.push_back(i);
                }
            }
        }

        if (all_of(T.begin(), T.end(), [](auto s){return s == '*';})) {
            return {};
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};