# include <vector>
using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size() + 1);
        for (int i = 0; i < arr.size(); ++i) {
            auto maxVal = arr[i], tmp = dp[i] + arr[i];
            for (int j = 1; j < min(k, i - j); j++) {
                maxVal = max(maxVal, arr[i - j]);
                tmp = max(tmp, dp[i - j] + (j + 1) * maxVal);
            }
            dp[i + 1] = tmp;
        }

        return dp.back();
    }
};