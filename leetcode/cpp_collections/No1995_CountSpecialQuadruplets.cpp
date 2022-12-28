# include <vector>
# include <unordered_map>
using namespace std;

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int cnt = 0;
        unordered_map<int, int> cnter;
        for (int c = 1; c < nums.size() - 1; ++c) {
            for (int d = c + 1; d < nums.size(); ++d)
                cnt += cnter[nums[d] - nums[c]];
            for (int b = 0; b < c; ++b)
                ++cnter[nums[c] + nums[b]];
        }
        return cnt;
    }
};