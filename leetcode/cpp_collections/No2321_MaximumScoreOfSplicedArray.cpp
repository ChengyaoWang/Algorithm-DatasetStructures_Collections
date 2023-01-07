# include <vector>
# include <numeric>
# include <algorithm>
using namespace std;

class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int maxVal1 = numeric_limits<int>::min(), tmp1 = 0;
        int maxVal2 = numeric_limits<int>::min(), tmp2 = 0;
        for (int i = 0; i < n; ++i) {
            auto diff = nums2[i] - nums1[i];
            tmp1 = max(tmp1 - diff, 0);
            tmp2 = max(tmp2 + diff, 0);

            maxVal2 = max(maxVal2, tmp1);
            maxVal1 = max(maxVal1, tmp2);
        }

        int cum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int cum2 = accumulate(nums2.begin(), nums2.end(), 0);
        return max(cum1 + maxVal1, cum2 + maxVal2);
    }
};