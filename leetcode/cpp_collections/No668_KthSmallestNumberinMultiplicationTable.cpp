# include <vector>
# include <functional>
using namespace std;

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        
        function<int (int)> countLess = [&](int num) {
            int ret = 0;
            for (int i = 1; i <= m; ++i) {
                ret += min(num / i, n);
            }
            return ret;
        };

        int lo = 1, hi = m * n + 1, mid;
        while (lo < hi) {
            mid = (lo + hi) / 2;
            int cnt = countLess(mid);
            if (cnt <= k) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        
        return lo;
    }
};
