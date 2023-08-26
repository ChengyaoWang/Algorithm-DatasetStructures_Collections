# include <vector>
# include <numeric>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {

        long long sum1 = 0LL, sum2 = 0LL, tmp = 0LL;
        long long ret = 0LL;
        for (auto& i: arr) {
            if (i & 1) {
                sum1 += tmp + 1;
                ret += sum1 + sum2 * tmp;
                swap(sum1, sum2);
                tmp = 0LL;
            } else {
                ++tmp;
            }
        }

        ret += sum2 * tmp;

        return int(ret % 1000000007);
    }
};