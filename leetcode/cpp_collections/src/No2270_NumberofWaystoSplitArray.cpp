# include <vector>
# include <numeric>
using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        
        long long ret = 0, l = 0, r = accumulate(nums.begin(), nums.end(), 0LL);
        for (int i = 0; i < nums.size() - 1; ++i) {
            l += nums[i];
            r -= nums[i];
            if (l >= r) {
                ++ret;
            }
        }
        return (int)ret;
    }
};