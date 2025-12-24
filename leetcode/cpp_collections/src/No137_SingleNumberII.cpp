# include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int a = 0, b = 0, tmp_a;
        for (auto &i: nums) {
            tmp_a = a;
            // a = (tmp_a ^ i) & b;
            a = (~tmp_a & b & i) | (tmp_a & ~b & ~i);
            b = ~tmp_a & (i ^ b);
        }

        return b;
    }
};
