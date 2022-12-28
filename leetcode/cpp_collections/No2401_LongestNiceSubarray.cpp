# include <vector>
using namespace std;

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int setBits = 0, j = 0, res = 1;

        for (int i = 0; i < nums.size(); ++i) {

            while ((setBits & nums[i]) != 0) {
                setBits ^= nums[j++];
            }
            setBits |= nums[i];
            res = max(res, i - j + 1);
        }

        return res;
    }
};