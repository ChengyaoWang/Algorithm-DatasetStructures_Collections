# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {

        vector<pair<int, int>> cumVec = {{-1, 0}};
        for (auto& vec: flowers) {
            cumVec.emplace_back(vec[0], 1);
            cumVec.emplace_back(vec[1] + 1, -1);
        }
        
        sort(cumVec.begin(), cumVec.end());
        for (int i = 1; i < cumVec.size(); ++i) {
            cumVec[i].second += cumVec[i - 1].second;
        }

        vector<int> ret = {};
        for (auto& i: people) {
            auto it = upper_bound(
                cumVec.begin(), cumVec.end(), i,
                [&](int tgt, pair<int, int> &p) {
                    return tgt < p.first;
                }
            );
            --it;
            ret.push_back(it ->second);
        }

        return ret;
    }
};