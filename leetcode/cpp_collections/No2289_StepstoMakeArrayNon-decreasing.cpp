# include <vector>

using namespace std;

class Solution {
public:
    int totalSteps(vector<int>& nums) {
        vector<int> s;
        vector<int> dp(nums.size(), 0);
        int retVal = 0;

        for (int i = nums.size() - 1; i >= 0; --i) {

            while (!s.empty() && nums[s.back()] < nums[i]) {
                dp[i] = max(++dp[i], dp[s.back()]);
                s.pop_back();
                retVal = max(retVal, dp[i]);
            }

            s.push_back(i);
        }

        return retVal;
    }
};