# include <vector>
# include <unordered_map>
using namespace std;

class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {

        int n = nextVisit.size();
        vector<long long> dp(n);
        
        for (int i = 1; i < n; ++i) {
            dp[i] = 2 * dp[i - 1] - dp[nextVisit[i - 1]] + 2;
            dp[i] = (dp[i] + 1000000007LL) % 1000000007LL;
        }

        return (int)dp.back();
    }
};