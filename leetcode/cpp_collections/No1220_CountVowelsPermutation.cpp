# include <vector>
# include <numeric>
using namespace std;

class Solution {
public:
    int countVowelPermutation(int n) {

        vector<vector<long long>> cnt(2, vector<long long> (5, 1));
        int i = 0;
        for (; i < n; ++i) {
            int idx = i % 2, r_idx = 1 - idx;
            fill(cnt[idx].begin(), cnt[idx].end(), 0);

            cnt[idx][0] = (cnt[r_idx][1]) % 1000000007;
            cnt[idx][1] = (cnt[r_idx][0] + cnt[r_idx][2]) % 1000000007;
            cnt[idx][2] = (cnt[r_idx][0] + cnt[r_idx][1] + cnt[r_idx][3] + cnt[r_idx][4]) % 1000000007;
            cnt[idx][3] = (cnt[r_idx][2] + cnt[r_idx][4]) % 1000000007;
            cnt[idx][4] = (cnt[r_idx][0]) % 1000000007;
        }

        return accumulate(cnt[i % 2].begin(), cnt[i % 2].end(), 0LL) % 1000000007;
    }
};