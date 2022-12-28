# include <vector>

/*
    [0,1,1,1],
    [1,1,1,1],
    [0,1,1,1],

    0, 1, 2, 3
    1, 3, 5, 7
    1, 4, 7, 10
*/

class Solution {
public:
    int countSquares(std::vector<std::vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));

        int retCnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++){

                if (matrix[i][j] == 1) {
                    dp[i][j] = 1;
                    if (
                        (i > 0) && (j > 0) && 
                        (matrix[i][j-1] == 1) && 
                        (matrix[i-1][j] == 1) && 
                        (matrix[i-1][j-1] == 1)
                    ) {
                        dp[i][j] = std::min(
                            std::min(
                                dp[i - 1][j - 1],
                                dp[i - 1][j]
                            ), dp[i][j - 1]
                        ) + 1;
                    }
                }
                retCnt += dp[i][j];
            }
        }

        return retCnt;
    }
};