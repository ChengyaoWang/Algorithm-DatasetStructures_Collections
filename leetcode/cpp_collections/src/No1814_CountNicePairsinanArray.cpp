# include <vector>
# include <unordered_map>
using namespace std;

class Solution {
public:
    int revNumber(int inp) {
        int ret = 0;
        while (inp) {
            ret = 10 * ret + inp % 10;
            inp /= 10;
        }
        return ret;
    }
    int countNicePairs(vector<int>& nums) {

        long long ret = 0LL;
        unordered_map<int, int> cnter;
        for (auto& i: nums) {
            ret += cnter[revNumber(i) - i]++;
            ret %= 1000000007;
        }

        return (int)ret;
    }
};