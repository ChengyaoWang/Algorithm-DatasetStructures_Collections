# include <vector>
# include <numeric>
# include <algorithm>
# include <functional>
using namespace std;

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(), batteries.end(), greater<int>());
        long long totalSum = accumulate(batteries.begin(), batteries.end(), 0LL);

        int i = 0;
        for (; i < batteries.size(); ++i) {
            auto tmp = totalSum / (n - i);
            if (batteries[i] <= tmp)
                return tmp;
            totalSum -= batteries[i];
        }

        return -1;
    }
};