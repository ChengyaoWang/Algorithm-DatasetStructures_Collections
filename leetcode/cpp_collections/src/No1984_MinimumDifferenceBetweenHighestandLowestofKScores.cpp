# include <vector>
# include <numeric>
# include <algorithm>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        --k;
        int ret = numeric_limits<int>::max();
        for (int i = 0; i < nums.size() - k; ++i) {
            ret = min(ret, nums[i + k] - nums[i]);
        }
        return ret;        
    }
};