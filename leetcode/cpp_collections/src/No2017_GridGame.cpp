# include <vector>
# include <numeric>
# include <functional>
using namespace std;

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> firstRow(1), secondRow(1);
        for (int i = 0; i < n; ++i) {
            firstRow.push_back(firstRow.back() + grid[0][i]);
            secondRow.push_back(secondRow.back() + grid[1][i]);
        }

        function<long long (int, int)> cal = [&](int i, int j) {
            if (i <= j)
                return firstRow[j + 1] - firstRow[i + 1];
            return secondRow[i] - secondRow[j];
        };

        long long ret = numeric_limits<long long>::max();
        for (int i = 0; i < n; ++i) {
            long long tmp = max(cal(i, 0), cal(i, n - 1));
            ret = min(ret, tmp);
        }

        return ret;
    }
};