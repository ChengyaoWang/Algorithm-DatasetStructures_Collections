# include <vector>
# include <numeric>
using namespace std;

class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        for (int i = 1; i < stones.size(); ++i) {
            stones[i] += stones[i - 1];
        }
        int ret = stones.back();
        for (int i = stones.size() - 2; i >= 0; --i) {
            ret = max(ret, stones[i] - ret);
        }
        return ret;
    }
};