# include <vector>
# include <numeric>
# include <limits>
using namespace std;

class Solution {
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> enc(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                enc[j] |= (matrix[i][j] << i);
            }
        }
        return m - dfsHelper(enc, 0, 0, numSelect);
    }

    int dfsHelper(vector<int> enc, int depth, int activeCnt, int maxDepth) {
        if (activeCnt == maxDepth) {
            auto agg = accumulate(enc.begin(), enc.end(), 0, [](int &res, int b){
                return res | b;
            });
            int cnt = 0;
            while (agg) {
                cnt += (agg % 2);
                agg >>= 1;
            }
            return cnt;
        }

        int res = numeric_limits<int>::max();
        if ((maxDepth - activeCnt) < (enc.size() - depth))
            res = min(res, dfsHelper(enc, depth + 1, activeCnt, maxDepth));
        enc[depth] = 0;
        res = min(res, dfsHelper(enc, depth + 1, activeCnt + 1, maxDepth));

        return res;        
    }
};