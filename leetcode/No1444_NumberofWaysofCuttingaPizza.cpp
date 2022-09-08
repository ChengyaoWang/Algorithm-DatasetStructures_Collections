# include <vector>
# include <string>

using namespace std;

class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int row = pizza.size(), col = pizza[0].length();

        // First, Initialize cumcnt
        vector<vector<int>> cumcnt(row, vector<int>(col, 0));
        for (int i = row - 1; i >= 0; --i) {
            for (int j = col - 1; j >= 0; --j) {
                cumcnt[i][j] = pizza[i][j] == 'A';
                if (i < row - 1 && j < col - 1) {
                    cumcnt[i][j] += cumcnt[i + 1][j] + cumcnt[i][j + 1] - cumcnt[i + 1][j + 1];
                } else if (i < row - 1) {
                    cumcnt[i][j] += cumcnt[i + 1][j];
                } else if (j < col - 1) {
                    cumcnt[i][j] += cumcnt[i][j + 1];
                }
            }
        }
        
        // Second, Start dp
        vector<vector<vector<int>>> dp(k, vector<vector<int>> (row, vector<int> (col, 0)));
        for (int kk = 0; kk < k; ++kk) {
            for (int i = row - 1; i >= 0; --i) {
                for (int j = col - 1; j >= 0; --j) {
                    if (kk == 0) {
                        dp[kk][i][j] = cumcnt[i][j] > 0;
                    } else {
                    for (int q = i + 1; q < row; ++q) 
                        if (cumcnt[i][j] > cumcnt[q][j])
                            dp[kk][i][j] = (dp[kk][i][j] + dp[kk - 1][q][j]) % 1000000007;
                    for (int q = j + 1; q < col; ++q) 
                        if (cumcnt[i][j] > cumcnt[i][q])
                            dp[kk][i][j] = (dp[kk][i][j] + dp[kk - 1][i][q]) % 1000000007;
                    }
                }
            }
        }

        return dp[k - 1][0][0];
    }
};