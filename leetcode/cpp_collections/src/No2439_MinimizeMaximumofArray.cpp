# include <math.h>
# include <vector>
using namespace std;

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int ret = -1;
        double cumSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            cumSum += (double)nums[i];
            ret = max(ret, (int)ceil(cumSum / (i + 1)));

        }

        return ret;
    }
};