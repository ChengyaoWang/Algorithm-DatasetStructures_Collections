# include <vector>
# include <limits>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ret = 0, p1 = 0;
        nums1.push_back(numeric_limits<int>::max());
        for (int p2 = 0; p2 < nums2.size(); ++p2) {
            while (p1 < nums1.size() - 1 && nums1[p1] > nums2[p2]) {
                ++p1;                    
            }
            if (nums1[p1] <= nums2[p2])
                ret = max(ret, max(0, p2 - p1));
        }

        return ret;
    }
};