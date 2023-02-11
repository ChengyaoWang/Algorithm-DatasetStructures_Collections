# include <vector>
# include <numeric>
using namespace std;


class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int N = books.size();
        vector<int> dp(N + 1, numeric_limits<int>::max());
        dp[0] = 0;
        for (int i = 1; i <= N; ++i) {
            int w = 0, h = 0, ii = i;
            while(ii > 0) {
                w += books[ii - 1][0];
                if (w > shelfWidth)
                    break;
                h = max(h, books[ii - 1][1]);
                dp[i] = min(dp[i], dp[ii - 1] + h);
                --ii;
            }
        }
        
        return dp.back();
    }
};