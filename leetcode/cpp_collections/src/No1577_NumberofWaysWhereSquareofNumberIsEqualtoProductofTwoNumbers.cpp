# include <vector>
# include <unordered_map>
using namespace std;

typedef long long ll;

class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        return cntTriplets(nums1, nums2) + cntTriplets(nums2, nums1);
    }

    int cntTriplets(vector<int>& nums1, vector<int>& nums2) {
        ll tgt;
        int res = 0;
        unordered_map<ll, int> cnter = {};
        for (int elem: nums2) {
            tgt = (ll)elem * elem;
            for (int i: nums1) {
                if (tgt % i == 0)
                    res += cnter[tgt / i];
                ++cnter[i];
            }
            cnter.clear();
        }

        return res;
    }
};