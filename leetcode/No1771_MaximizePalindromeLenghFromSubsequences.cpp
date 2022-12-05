# include <vector>
# include <string>
using namespace std;

class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        
        string word = word1 + word2;
        int l = word.size(), th = word1.size();

        vector<vector<int>> dp(l + 1, vector<int> (l + 1, 0));
        int res = 0, j;

        for (int ll = 1; ll <= l; ++ll) {
            for (int i = 0; i <= l - ll; ++i) {
                j = i + ll;
                if (ll == 1) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                    if (word[i] == word[j - 1]) {
                        dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 2);
                        if (i < th && j > th) {
                            res = max(res, dp[i][j]);
                        }
                    }
                }
            }
        }
        return res;
    }
};