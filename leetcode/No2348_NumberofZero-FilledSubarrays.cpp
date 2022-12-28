# include <vector>
using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long cumSum = 0, res = 0;
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            cumSum += nums[i];
            while (cumSum != 0) {
                cumSum -= nums[j++];
            }
            res += (i - j + 1);
        }
        return res;
    }
};