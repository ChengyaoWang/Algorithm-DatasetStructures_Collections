# include <vector>
# include <unordered_set>
using namespace std;

class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        
        long long ret = 0LL;
        vector<int> setBitsCnt(32);
        unordered_set<int> mem(nums.begin(), nums.end());
        for (auto& i: mem)
            ++setBitsCnt[__builtin_popcount(i)];

        for (int i = 0; i <= 31; ++i) {
            for (int j = max(k - i, i); j <= 31; ++j) {
                ret += 2 * setBitsCnt[i] * setBitsCnt[j];
            }
            if (2 * i >= k)
                ret -= setBitsCnt[i] * setBitsCnt[i];
        }

        return ret;
    }
};
