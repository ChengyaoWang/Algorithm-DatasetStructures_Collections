# include <vector>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ret = 0;
        for (int i = n - 1; i >= 0; --i) {
            int lo = 0, hi = i - 1;
            while (lo < hi) {
                while (lo < hi && nums[lo] + nums[hi] <= nums[i]) {
                    ++lo;
                }
                ret += max(0, hi - lo);
                --hi;
            }
        }

        return ret;
    }
};