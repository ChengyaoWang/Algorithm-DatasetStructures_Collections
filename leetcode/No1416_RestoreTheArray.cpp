# include <vector>
# include <string>

using namespace std;

class Solution {
public:
    int numberOfArrays(string s, int k) {
        vector<long> dp(s.length() + 1, 0);
        dp[s.length()] = 1;
        
        int ii;
        long elem;
        for (int i = s.length() - 1; i >= 0; --i) {
            
            if (s[i] == '0') {
                continue;
            }
            
            for (ii = i, elem = 0; ii < s.length(); ++ii) {
                elem = 10 * elem + (s[ii] - '0');
                if (elem > k) {
                    break;
                }
                dp[i] = (dp[i] + dp[ii + 1]) % 1000000007;
            }
        }

        return dp.front() % 1000000007;
    }
};