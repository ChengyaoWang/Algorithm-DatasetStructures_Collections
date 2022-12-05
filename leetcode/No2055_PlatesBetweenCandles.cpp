# include <string>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> cumSum = {0};

        for (auto elem: s) {
            cumSum.push_back(cumSum.back() + int(elem == '|'));
        }
        
        vector<int> res = {};
        for (auto p: queries) {
            auto lo = upper_bound(cumSum.begin() + p[0], cumSum.begin() + p[1] + 1, cumSum[p[0]]) - cumSum.begin();
            auto hi = upper_bound(cumSum.begin() + p[0], cumSum.begin() + p[1] + 1, cumSum[p[1] + 1] - 1) - cumSum.begin();
            res.push_back(max(0, int(hi - lo + 1 - cumSum[hi] + cumSum[lo - 1])));
        }

        return res;
    }
};