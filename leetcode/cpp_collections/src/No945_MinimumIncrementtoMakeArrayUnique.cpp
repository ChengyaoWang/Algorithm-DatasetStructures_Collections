# include <vector>
# include <algorithm>

using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int init = 1, res = 0;
        for (auto i: nums) {
            res += max(0, init++ - i);
            init = max(init, i);
        }

        return res;
    }
};