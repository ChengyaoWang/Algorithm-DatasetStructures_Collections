# include <vector>
using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int ret = 0, i = 0;
        long long cumSum = 0;
        while (cumSum < n) {
            if (i < nums.size() && cumSum >= nums[i] - 1) {
                cumSum += nums[i++];
            } else {
                cumSum += (cumSum + 1);
                ++ret;
            }
        }
        return ret;
    }
};