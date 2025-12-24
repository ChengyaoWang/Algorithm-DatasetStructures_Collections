# include <vector>
using namespace std;

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int ret = 0;
        for (auto i: nums) {
            ret += i;
            while (i) {
                ret -= (i % 10);
                i /= 10;
            }
        }
        return abs(ret);
    }
};