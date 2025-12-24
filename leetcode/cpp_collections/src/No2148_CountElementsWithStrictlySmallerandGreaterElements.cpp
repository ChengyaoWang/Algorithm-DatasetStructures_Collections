# include <vector>
# include <numeric>
using namespace std;

class Solution {
public:
    int countElements(vector<int>& nums) {

        int minV = numeric_limits<int>::max();
        int maxV = numeric_limits<int>::min();
        int multi_min = 0, multi_max = 0;

        for (auto& i: nums) {
            if (i < minV) {
                minV = i;
                multi_min = 1;
            } else if (i == minV) {
                ++multi_min;
            } 
            if (i > maxV) {
                maxV = i;
                multi_max = 1;
            } else if (i == maxV) {
                ++multi_max;
            }

        }

        return nums.size() - min(multi_min + multi_max, (int)nums.size());
    }
};