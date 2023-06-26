# include <string>
# include <vector>
using namespace std;

class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if (s.size() != t.size())   return false;
        vector<int> cnt(26);
        for (int i = 0; i < 26; ++i)
            cnt[i] = k / 26 + (i <= k % 26);

        for (int i = 0; i < s.size(); ++i) {
            auto gap = (t[i] - s[i] + 26) % 26;
            if (--cnt[gap] < 0 && gap != 0)
                return false;
        }
        return true;
    }
};