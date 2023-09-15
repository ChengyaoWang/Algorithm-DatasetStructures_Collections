# include <vector>
# include <string>
using namespace std;

using ll = long long;

class Solution {
public:
    ll MOD_NUM = 1000000007LL;

    void createDP(vector<vector<ll>>& dp, int depth) {
        
        dp.emplace_back(10, 1LL);

        for (int i = 0; i < depth - 1; ++i) {
            vector<ll> dpTmp(10, 0LL);
            for (int j = 0; j < 10; ++j) {
                if (j == 0 || j == 9) {
                    dpTmp[j] = dp.back()[j == 0 ? 1: 8];
                } else {
                    dpTmp[j] = dp.back()[j - 1] + dp.back()[j + 1];
                }
                dpTmp[j] %= MOD_NUM;
            }
            dp.push_back(dpTmp);
        }
    }

    bool isStepping(string& s) {
        char prevC = '\0';
        for (auto& c: s) {
            if (abs(prevC - c) != 1 && prevC != '\0')
                return false;
            prevC = c;
        }
        return true;
    }

    ll returnResult(vector<vector<ll>>& dp, string& s) {

        if (s.size() == 1)
            return (s[0] - '0');

        ll ret = 0LL;
        for (int i = 0; i < s.size(); ++i) {
            auto upper = (i == s.size() - 1) ? s.front() - '0': 10;
            for (int j = 1; j < upper; ++j) {
                ret = (ret + dp[i][j]) % MOD_NUM;
            }
        }

        for (int i = 0; i < s.size() - 1; ++i) {
            auto curDigit = s[i] - '0', nextDigit = s[i + 1] - '0';
            if (nextDigit > curDigit - 1 && curDigit > 0) {
                ret = (ret + dp[s.size() - 2 - i][curDigit - 1]) % MOD_NUM;
            }
            if (nextDigit > curDigit + 1 && curDigit < 9) {
                ret = (ret + dp[s.size() - 2 - i][curDigit + 1]) % MOD_NUM;
            }
            if (abs(curDigit - nextDigit) != 1)
                break;
        }

        return ret % MOD_NUM + isStepping(s);
    }

    int countSteppingNumbers(string low, string high) {

        vector<vector<ll>> dp;
        createDP(dp, max(low.size(), high.size()));
        
        ll lowRes = returnResult(dp, low);
        ll highRes = returnResult(dp, high);
        ll ret = highRes - lowRes + isStepping(low) + MOD_NUM;

        return (int)(ret % MOD_NUM);
    }
};