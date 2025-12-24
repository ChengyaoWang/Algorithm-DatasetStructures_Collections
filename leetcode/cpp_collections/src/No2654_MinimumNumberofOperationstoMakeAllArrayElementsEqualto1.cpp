# include <vector>
using namespace std;

class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    int minOperations(vector<int>& nums) {

        auto gcdAll = nums[0], one_cnt = 0;
        for (auto& i: nums) {
            gcdAll = gcd(gcdAll, i);
            one_cnt += (i == 1);
        }
        if (one_cnt > 0) {
            return nums.size() - one_cnt;
        } else if (gcdAll != 1) {
            return -1;
        }

        int ret = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            auto elem = nums[i];
            for (int j = i + 1; j < nums.size(); ++j) {
                elem = gcd(elem, nums[j]);
                if (elem == 1) {
                    ret = min(ret, j - i + 1);
                    break;
                }                
            }
        }
        return ret + nums.size() - 2;
    }
};