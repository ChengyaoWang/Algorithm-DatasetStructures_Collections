# include <vector>
using namespace std;

class Solution {
public:
    int monkeyMove(int n) {
        long long ret = 1LL, pwr = 2LL;
        long long MOD_NUM = 1000000007LL;

        for (int i = 0; i < 32; ++i) {
            if (n & (1 << i)) {
                ret = (ret * pwr) % MOD_NUM;
            }
            pwr = (pwr * pwr) % MOD_NUM;
        }

        return (ret - 2LL + MOD_NUM) % MOD_NUM;
    }
};