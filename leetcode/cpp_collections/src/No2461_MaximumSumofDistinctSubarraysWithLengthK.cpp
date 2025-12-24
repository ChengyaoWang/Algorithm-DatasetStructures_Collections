# include <vector>
# include <unordered_map>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ret = 0, subSum = 0;
        unordered_map<int, int> cnter = {};
        for (int i = 0; i < nums.size(); ++i) {
            ++cnter[nums[i]];
            subSum += nums[i];
            if (i >= k) {
                --cnter[nums[i - k]];
                subSum -= nums[i - k];
                if (cnter[nums[i - k]] == 0)
                    cnter.erase(nums[i - k]);
            }
            if (i >= k - 1 && cnter.size() == k) {
                ret = max(ret, subSum);
            }
        }
        return ret;
    }
};