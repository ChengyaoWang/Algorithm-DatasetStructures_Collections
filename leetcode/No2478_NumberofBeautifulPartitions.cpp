# include <string>
# include <vector>
# include <numeric>
# include <algorithm>
using namespace std;

class Solution {
public:
    int beautifulPartitions(string s, int Kim, int m) {

        int mod = 1e9+7;
        auto isPrime = [](char c){
            return (c == '2' || c == '3' || c == '5' || c == '7');
        };

        vector<vector<long long>> dp(Kim + 2, vector<long long>(s.size() + 2, 0));
        for(int k = 1; k <= Kim; ++k){
            long long re = 0;
            for(int i = 0; i < s.size(); ++i){
                if (i >= m && isPrime(s[i - m + 1])) re = (re + dp[k - 1][i - m]) % mod;
                if (k == 1) {
                    if(i + 1 >= m && isPrime(s[0]) && !isPrime(s[i])) dp[k][i] = 1;
                } else {
                    if(!isPrime(s[i])) dp[k][i] = re;
                }
            }
        }
        return dp[Kim][s.size()-1];
    }
};