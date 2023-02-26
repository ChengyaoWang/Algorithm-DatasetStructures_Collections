# include <vector>
# include <unordered_map>
using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {

        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (n, 1));
        unordered_map<int, int> mem = {};
        for (int i = 0; i < n; ++i)
            mem[arr[i]] = i;

        int ret = 1;
        for (int i = 2; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                auto tmp = arr[i] - arr[j];
                if (arr[j] <= tmp)   continue;
                if (mem.find(tmp) == mem.end()) continue;
                dp[i][j] = max(dp[i][j], max(dp[j][mem[tmp]], 2) + 1);
            }

            ret = max(ret, *max_element(dp[i].begin(), dp[i].end()));
        }
        return ret < 3 ? 0: ret;
    }
};