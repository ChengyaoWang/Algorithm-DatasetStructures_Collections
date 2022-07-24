# include <vector>
# include <limits>

using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {

        vector<int> dp(366, numeric_limits<int>::max());
        dp[0] = 0;
        
        int ii = 1;
        for (auto &i: days) {
            
            while (ii < i && ii < 365) {
                dp[ii] = dp[ii - 1];
                ++ii;
            }
            
            dp[i] = min(dp[i], dp[i - 1] + costs[0]);
            dp[i] = min(dp[i], dp[max(i - 7, 0)] + costs[1]);
            dp[i] = min(dp[i], dp[max(i - 30, 0)] + costs[2]);
        }

        return dp[days.back()];
    }
};