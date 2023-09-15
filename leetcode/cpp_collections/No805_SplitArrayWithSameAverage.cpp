# include <vector>
# include <numeric>
using namespace std;

class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {

        int N = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        vector<int> dp(sum + 1, 0);
        dp[0] = 1;

        for (auto& i: nums) {
            for (int j = sum; j >= i; --j) {
                dp[j] |= (dp[j - i] << 1);
            }
        }

       for(int i = 1; i < N; i++) {
            if (((sum * i) % N == 0) && ((1 << i) & dp[sum * i / N])) {
                return true;
            }
        }
        return false;        
    }
};