# include <vector>
using namespace std;

class Solution {
public:

    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        if (b > a) {
            swap(a, b);
        }
        return gcd(b, a % b);
    }

    int subarrayGCD(vector<int>& nums, int k) {

        int ret = 0;
        for (int i = 0; i < nums.size(); ++i) {
            auto cul = nums[i], j = i;
            for (; j < nums.size(); ++j) {
                cul = gcd(cul, nums[j]);
                if (cul == k) {
                    ++ret;
                } else if (cul < k) {
                    break;
                }
            }
        }
        return ret;
    }
};