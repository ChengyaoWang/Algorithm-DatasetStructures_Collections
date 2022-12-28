# include <vector>
# include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int tgt = -1, l, r;
        int ans = 1e7, gap, opt_gap = 1e7;

        for (int i = 0; i < nums.size() - 2; ++i) {
            tgt = target - nums[i];
            l = i + 1;
            r = nums.size() - 1;

            while (l < r) {

                gap = tgt - (nums[l] + nums[r]);

                if (abs(gap) < opt_gap) {
                    ans = nums[i] + nums[l] + nums[r];
                    opt_gap = abs(gap);
                }

                if (gap < 0) {
                    --r;
                } else {
                    ++l;
                }

            }
        }

        return ans;
    }
};