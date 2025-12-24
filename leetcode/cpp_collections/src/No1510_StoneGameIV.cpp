# include <vector>

using namespace std;

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);

        // Sorted Potential Moves       
        vector<int> moves = {};
        for (int i = 1; i < 317; ++i) {
            moves.push_back(i * i);
        }
        
        // Begin Iteration
        bool tmp_res;
        for (int i = 1; i <= n; ++i) {
            tmp_res = false;
            for (auto &m: moves) {
                if (m > i) {
                    break;
                }
                tmp_res |= !dp[i - m];
            }
            dp[i] = tmp_res;
        }

        return dp.back();
    }
};