# include <vector>
# include <numeric>
# include <set>
using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        
        int ret = numeric_limits<int>::min();
        int m = matrix.size(), n = matrix[0].size();

        for (int lo = 0; lo < n; ++lo) {
            vector<int> partialSum(m, 0);
            for (int up = lo; up < n; ++up) {
                int tmp = 0;
                int maxPartialSum = numeric_limits<int>::min();
                for (int r = 0; r < m; ++r) {
                    partialSum[r] += matrix[r][up];
                    tmp = max(tmp + partialSum[r], partialSum[r]);
                    maxPartialSum = max(maxPartialSum, tmp);
                }
                set<int> mem = {0};
                int runningSum = 0;
                for (auto& i: partialSum) {
                    runningSum += i;
                    auto it = mem.lower_bound(runningSum - k);
                    if (it != mem.end()) {
                        ret = max(ret, runningSum - *it);
                    }
                    mem.insert(runningSum);
                }
            }
        }
        return ret;
    }
};