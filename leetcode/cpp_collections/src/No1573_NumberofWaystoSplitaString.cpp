# include <string>
# include <limits>
using namespace std;

class Solution {
public:
    int numWays(string s) {
        int sum = 0;
        for (auto c: s)
            sum += (c == '1');
        if (sum % 3 != 0) {
            return 0;
        } else if (sum == 0) {
            long long slots = s.size() - 2;
            return (slots * (slots - 1) % 1000000007);
        }

        int cumSum = 0;
        sum /= 3;
        int l1 = numeric_limits<int>::max(), l2 = numeric_limits<int>::max();
        int r1 = numeric_limits<int>::min(), r2 = numeric_limits<int>::min();
        for (int i = 0; i < s.size(); ++i) {
            if (cumSum == sum) {
                l1 = min(l1, i);
                r1 = max(r1, i);
            } else if (cumSum == 2 * sum) {
                l2 = min(l2, i);
                r2 = max(r2, i);
            }
            cumSum += (s[i] == '1');
        }
        long long slots1 = r1 - l1, slots2 = r2 - l2;
        return (slots1 * slots2 % 1000000007);
    }
};