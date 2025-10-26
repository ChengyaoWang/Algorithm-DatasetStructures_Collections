# include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int maxIdx = 0, step = 0, maxIdx_tmp = 0;

        for (int i = 0; i < n; ++i) {
            if (maxIdx >= n - 1)
                return step;
            maxIdx_tmp = max(maxIdx_tmp, i + nums[i]);
            if (i == maxIdx) {
                maxIdx = maxIdx_tmp;
                ++step;
            }
        }
        return -1;
    }
};