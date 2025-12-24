# include <vector>
# include <numeric>
# include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        potions.push_back(numeric_limits<int>::min());
        sort(potions.begin(), potions.end());
        vector<int> res = {};
        for (auto elem: spells) {
            auto tgt = int(success / elem) + (success % elem != 0);
            if (tgt < 0)    tgt = numeric_limits<int>::max();
            auto tgt_idx = lower_bound(potions.begin(), potions.end(), tgt);
            res.push_back(potions.end() - tgt_idx);
        }
        return res;
    }
};