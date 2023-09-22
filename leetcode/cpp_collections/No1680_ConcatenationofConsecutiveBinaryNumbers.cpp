
using ll = long long;

class Solution {
public:
    int concatenatedBinary(int n) {        
        ll ret = 0, l = 0;
        ll MOD_NUM = 1000000007;

        for (int i = 1; i <= n; ++i) {
            if (__builtin_popcount(i) == 1) {
                ++l;
            }
            ret = ((ret << l) + i) % MOD_NUM;
        }
        return (int)ret;
    }
};