# include <vector>
# include <functional>
# include <algorithm>
using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        function<vector<int> (int, int)> getArrWeNeed = [&](
            int st, int et
        ){
            vector<int> ret = {};
            int step = st < et ? 1: -1;
            int j = st, partialSum = 0, minSize = n;
            for (int i = st; i != et; i += step) {
                partialSum += arr[i];
                while (j != i && partialSum > target) {
                    partialSum -= arr[j];
                    j += step;
                }
                if (partialSum == target) {
                    minSize = min(minSize, abs(i - j));
                }
                ret.push_back(minSize + 1);
            }
            return ret;
        };

        auto prefixBest = getArrWeNeed(0, n);
        auto suffixBest = getArrWeNeed(n - 1, -1);
        reverse(suffixBest.begin(), suffixBest.end());

        int ret = 2 * n;
        for (int i = 0; i < n; ++i) {
            ret = min(ret, prefixBest[i] + suffixBest[i]);
        }

        return ret > n ? -1: ret;
    }
};