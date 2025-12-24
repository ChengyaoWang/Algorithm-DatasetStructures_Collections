# include <vector>
# include <limits>
# include <algorithm>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> forward(n), backward(n);
        int l = numeric_limits<int>::min() + 10000;
        int r = numeric_limits<int>::min() + 10000;

        for (int i = 0; i < n; ++i) {
            l = max(l + arr[i], arr[i]);
            r = max(r + arr[n - 1 - i], arr[n - 1 - i]);
            forward[i] = l;
            backward[n - 1 - i] = r;
        }

        int res = *max_element(arr.begin(), arr.end());
        for (int i = 0; i < n; ++i) {
            res = max(res, forward[i] + backward[i] - arr[i]);
            if (i < n - 2) {
                res = max(res, forward[i] + backward[i + 2]);
            }
        }
        return res;
    }
};