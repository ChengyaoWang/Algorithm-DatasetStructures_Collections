# include <vector>
# include <limits>

using namespace std;

class Solution {
private:
    int gcd(int a, int b) {
        if (b == 0) return a;
        if (a < b)  swap(a, b);
        return gcd(b, a % b);
    }
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size() / 2, comb = 1 << nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(comb, -1));
        dp[0][0] = 0;

        for (int op = 0; op < n; ++op) {
            for (int mask = 0; mask < comb; ++mask) {
                if (dp[op][mask] == -1)    continue;
                for (int i = 0; i < nums.size() - 1; ++i) {
                    if ((mask & (1 << i)) != 0)   continue;
                    for (int j = i + 1; j < nums.size(); ++j) {
                        if ((mask & (1 << j)) != 0)   continue;
                        auto newMask = mask + (1 << i) + (1 << j);
                        dp[op + 1][newMask] = max(
                            dp[op + 1][newMask],
                            (op + 1) * gcd(nums[i], nums[j]) + dp[op][mask]
                        );
                    }
                }
            }
        }
        
        return dp[n][comb - 1];
    }
};