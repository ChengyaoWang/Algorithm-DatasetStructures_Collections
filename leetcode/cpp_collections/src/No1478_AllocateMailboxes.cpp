# include <vector>
# include <algorithm>
using namespace std;
class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        int N = houses.size();
        sort(houses.begin(), houses.end());

        vector<int> dp(N, 1e7), cum(N + 1, 0);
        for (int i = 0; i < N; ++i)
            cum[i + 1] = cum[i] + houses[i];

        for (int kk = 0; kk < k; ++kk) {
            for (int j = N - 1; j >= 0; --j) {
                for (int i = 0; i <= j; ++i) {
                    auto mid = (i + j) / 2;
                    auto dl = (2 * mid - j - i) * houses[mid];
                    dl += (cum[j + 1] - cum[mid]) - (cum[mid + 1] - cum[i]);
                    dp[j] = min(dp[j], (i == 0 ? 0: dp[i - 1]) + dl);
                }
            }
        }

        return dp.back();
    }
};