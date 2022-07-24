# include <vector>
# include <algorithm>

using namespace std;

class Solution {
public:
    int numPrimeArrangements(int n) {

        // Prime Numbers
        vector<int> prime = {
            2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
            43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
        };
        auto n_prime = upper_bound(prime.begin(), prime.end(), n) - prime.begin();
        vector<int> fact_dp(max(n_prime, n - n_prime) + 1, 1);
        for (int i = 1; i < fact_dp.size(); ++i) {
            fact_dp[i] = (fact_dp[i - 1] * i) % 1000000007;
        }

        return (fact_dp[n_prime] * fact_dp[n - n_prime]) % 1000000007;
    }
};