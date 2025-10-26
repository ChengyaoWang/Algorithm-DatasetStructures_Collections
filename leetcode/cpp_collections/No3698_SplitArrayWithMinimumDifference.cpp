# include <vector>

using namespace std;

class Solution {
public:
    long long splitArray(vector<int>& nums) {

        long long l = 0, r = 0;
        int i, j;
        for (i = 0; i < nums.size() - 1; ++i) {
            if (nums[i + 1] <= nums[i]) {
                break;
            }
            l += nums[i];
        }
        for (j = nums.size() - 1; j > 0; --j) {
            if (nums[j - 1] <= nums[j]) {
                break;
            }
            r += nums[j];
        }

        if (abs(i - j) > 1)
            return -1;
        else if (abs(i - j) == 1)
            return abs(l - r);
        else
            return min(abs(l - r - nums[i]), abs(l - r + nums[i]));
    }
};