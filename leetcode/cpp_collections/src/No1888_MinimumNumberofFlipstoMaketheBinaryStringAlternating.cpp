# include <string>
# include <limits>
using namespace std;

class Solution {
public:
    int minFlips(string s) {
        int cnt[2][2] = {{0, 0}, {0, 0}};
        for (int i = 0; i < s.size(); ++i) {
            ++cnt[i % 2][s[i] - '0'];
        }

        int opt = numeric_limits<int>::min(), tmp;
        for (int i = 0; i < s.size(); ++i) {
            tmp = max(cnt[1][1] + cnt[0][0], cnt[1][0] + cnt[0][1]);
            opt = max(opt, tmp);

            --cnt[0][s[i] - '0'];
            swap(cnt[0][0], cnt[1][0]);
            swap(cnt[0][1], cnt[1][1]);
            ++cnt[(s.size() - 1) % 2][s[i] - '0'];
        }

        return s.size() - opt;
    }
};