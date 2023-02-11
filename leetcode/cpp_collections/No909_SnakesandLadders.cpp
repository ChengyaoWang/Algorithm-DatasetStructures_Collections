# include <queue>
# include <vector>
# include <numeric>
# include <functional>
using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int N = board.size();
        vector<vector<int>> dp(N, vector<int> (N, numeric_limits<int>::max()));
        function<pair<int, int> (int)> getLocFromStep = [&](int step) {
            step -= 1;
            int i = step / N;
            int j = (i % 2 == 0) ? step % N: N - 1 - step % N;
            return pair<int, int>{N - 1 - i, j};
        };
        function<int (vector<vector<int>>&, pair<int, int>)> getElemFromMx = [&](
            vector<vector<int>>& mx, pair<int, int> loc
        ) {
            return mx[loc.first][loc.second];
        };

        // priority_queue<int, vector<int>, greater<int>> q;
        queue<int> q = {};
        q.push(1);
        dp[N - 1][0] = 0;
        while(!q.empty()) {

            auto elem = q.front();
            auto val = getElemFromMx(dp, getLocFromStep(elem));
            q.pop();

            for (auto i = elem + 1; i <= min(elem + 6, N * N); ++i) {
                auto locNext = getLocFromStep(i);
                auto idx = i;
                auto boardVal = getElemFromMx(board, locNext);
                if (boardVal != -1) {
                    locNext = getLocFromStep(boardVal);
                    idx = boardVal;
                }
                if (val + 1 < getElemFromMx(dp, locNext)) {
                    dp[locNext.first][locNext.second] = val + 1;
                    q.push(idx);
                }   
            }
        }

        int ret = dp[0][N % 2 == 0 ? 0: N - 1];
        return ret == numeric_limits<int>::max() ? -1: ret;
    }
};