# include <vector>
# include <string>
# include <numeric>
using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {

        sort(timePoints.begin(), timePoints.end());
        auto tdiff = [](string a, string b) {
            int tmp = 60 * (10 * (a[0] - b[0]) + a[1] - b[1])
                + (10 * (a[3] - b[3]) + a[4] - b[4]);
            return tmp < 0 ? tmp + 24 * 60: tmp;
        };

        int ret = numeric_limits<int>::max();
        for (int i = 0; i < timePoints.size(); ++i) {
            ret = min(ret, tdiff(timePoints[(i + 1) % timePoints.size()], timePoints[i]));
        }

        return ret;
    }
};