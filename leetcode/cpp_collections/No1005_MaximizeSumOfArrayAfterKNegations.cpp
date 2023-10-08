# include <vector>
# include <algorithm>
# include <numeric>
using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        int flip_cnt = 0, ret = 0, min_abs = numeric_limits<int>::max();
        for (auto& i: nums) {
            if (flip_cnt < k && i < 0) {
                ret += abs(i);
                ++flip_cnt;
            } else {
                ret += i;
            }

            min_abs = min(min_abs, abs(i));
        }

        if ((k - flip_cnt) & 1) {
            ret -= 2 * min_abs;
        }

        return ret;
    }
};