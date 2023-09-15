# include <vector>
using namespace std;

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        vector<int> ret = {0, 0};
        int l, r;

        for (int i = 0; i < nums.size(); ++i) {
            l = (i == 0) ? 2000: nums[i - 1];
            r = (i == nums.size() - 1) ? 2000: nums[i + 1];
            ret[i % 2] += max(0, nums[i] - min(l, r) + 1);
        }

        return min(ret[0], ret[1]);
    }
};