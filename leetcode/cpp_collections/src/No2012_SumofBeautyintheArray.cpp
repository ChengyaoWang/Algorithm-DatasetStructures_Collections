# include <vector>
# include <numeric>
# include <algorithm>
using namespace std;

class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int ret = 0;

        vector<int> dp1, dp2;
        dp1.push_back(numeric_limits<int>::min());
        dp2.push_back(numeric_limits<int>::max());

        for (int i = 0; i < nums.size() - 1; ++i) {
            dp1.push_back(max(dp1.back(), nums[i]));
            dp2.push_back(min(dp2.back(), nums[nums.size() - 1 - i]));
        }
        reverse(dp2.begin(), dp2.end());

        for (int i = 1; i < nums.size() - 1; ++i) {
            if (dp1[i] < nums[i] && nums[i] < dp2[i]) {
                ret += 2;
            } else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
                ret += 1;
            } 
        }

        return ret;
    }
};