# include <vector>
# include <string>
# include <algorithm>
# include <unordered_map>
using namespace std;

class Solution {
public:

    string insertDigit(string s, char c) {
        auto loc = lower_bound(s.begin(), s.end(), c, greater<char>());
        s.insert(loc, c);
        return s;
    }

    string comp(const string& s1, const string& s2) {
        if (s1.size() == s2.size()) {
            int i = 0, n = s1.size();
            while (i < n && s1[i] == s2[i]) ++i;
            return s1[i] > s2[i] ? s1: s2;
        }
        return s1.size() > s2.size() ? s1: s2;
    }

    string largestNumber(vector<int>& cost, int target) {

        unordered_map<int, int> m;
        for (int i = 0; i < cost.size(); ++i)
            m[cost[i]] = i + 1;

        vector<string> dp(target + 1);
        dp[0] = "0";

        for (int i = 1; i <= target; ++i) {
            for (auto& kv: m) {
                if (kv.first <= i && dp[i - kv.first].size() > 0) {
                    auto elem = insertDigit(dp[i - kv.first], kv.second + '0');
                    dp[i] = comp(dp[i], elem);
                }
            }
        }

        string ret = dp.back();
        if (ret.size() == 0)
            return "0";
        
        ret.pop_back();
        return ret;
    }
};