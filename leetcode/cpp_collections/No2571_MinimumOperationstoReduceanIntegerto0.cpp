# include <vector>
using namespace std;

class Solution {
public:
    int minOperations(int n) {

        int ret = 0;
        while (n) {
            if ((n & 3) == 3) {
                ++ret;
                ++n;
            } else {
                ret += (n & 1) == 1;
                n >>= 1;
            }
        }

        return ret;
    }
};