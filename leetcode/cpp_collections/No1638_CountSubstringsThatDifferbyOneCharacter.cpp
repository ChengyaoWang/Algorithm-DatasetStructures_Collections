# include <vector>
# include <string>
using namespace std;

using mx = vector<vector<int>>;
class Solution {
public:
    int countSubstrings(string s, string t) {

        int m = s.size(), n = t.size();
        mx dpl(m, vector<int>(n, 1)), dpr(m, vector<int>(n, 1));
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (s[i - 1] == t[j - 1])
                    dpl[i][j] = dpl[i - 1][j - 1] + 1;
                if (s[m - i] == t[n - j])
                    dpr[m - 1 - i][n - 1 - j] = dpr[m - i][n - j] + 1;
            }
        }

        int ret = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ret += (dpl[i][j] * dpr[i][j]) * (s[i] != t[j]);
            }
        }

        return ret;
    }
};