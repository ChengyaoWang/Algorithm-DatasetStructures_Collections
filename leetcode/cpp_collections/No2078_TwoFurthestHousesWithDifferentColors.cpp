# include <vector>
# include <numeric>
# include <unordered_map>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& colors) {

        int ret = numeric_limits<int>::min();
        unordered_map<int, int> lastIdx = {};

        for (int i = 0; i < colors.size(); ++i) {
            auto elem = colors[i];
            for (auto& [k, v]: lastIdx) {
                if (k == elem) continue;
                ret = max(ret, i - v);
            }
            if (lastIdx.find(elem) == lastIdx.end())
                lastIdx[elem] = i;
        }

        return ret;
    }
};