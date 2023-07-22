# include <vector>
# include <numeric>
# include <algorithm>
using namespace std;

using ll = long long;
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {

        vector<int> cumSum = {0};
        for (int i = 0; i < 32; ++i) {
            if (n & (1 << i)) {
                cumSum.push_back(cumSum.back() + i);
            }
        }

        vector<int> ret = {};
        for (auto& p: queries) {
            auto power = cumSum[p[1] + 1] - cumSum[p[0]];
            auto result = 1LL;
            while (power) {
                auto l = min(__builtin_clz(result) - 1, power);
                result *= 1 << l;
                result %= 1000000007;
                power -= l;
            }
            ret.push_back(int(result));
        }
        return ret;
    }
};