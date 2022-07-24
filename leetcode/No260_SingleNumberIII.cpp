# include <vector>
# include <numeric>
# include <functional>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        int x = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        int xx = x, xy = x;
        int mask = x & ( ~ x + 1);

        for (auto &i: nums) {
            if ( i & mask == 0 ) {
                xx ^= i;
            } else {
                xy ^= i;
            }
        }

        return vector<int>{xx, xy};
    }
};