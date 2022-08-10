# include <vector>
# include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l = nums1.size() + nums2.size();
        if (l % 2 == 1) {
            return helper(nums1, nums2, l / 2);
        }
        return (helper(nums1, nums2, (l - 1) / 2) + helper(nums1, nums2, l / 2)) / 2.;
    }

    double helper(vector<int>& nums1, vector<int>& nums2, int k) {
        int left1 = 0, right1 = nums1.size();
        int left2 = 0, right2 = nums2.size();
        int ma, mb, ia, ib;

        while (true) {
            if (left1 == right1) {
                return nums2[left2 + k];
            } else if (left2 == right2) {
                return nums1[left1 + k];
            }

            ia = (right1 - left1) / 2;
            ib = (right2 - left2) / 2;
            ma = nums1[ia + left1];
            mb = nums2[ib + left2];
            
            if (ia + ib < k) {
                if (ma < mb) {
                    k -= (ia + 1);
                    left1 += ia + 1;
                } else {
                    k -= (ib + 1);
                    left2 += ib + 1;
                }
            } else {
                if (ma < mb) {
                    right2 = left2 + ib;
                } else {
                    right1 = left1 + ia;
                }
            }
        }
    }
};