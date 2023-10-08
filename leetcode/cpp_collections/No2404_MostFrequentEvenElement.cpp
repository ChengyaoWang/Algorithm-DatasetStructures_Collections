# include <vector>
# include <unordered_map>
using namespace std;

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {

        unordered_map<int, int> cnter;
        pair<int, int> opt = make_pair(-1, -1);

        for (auto& i: nums) {
            if (i & 1)
                continue;

            auto cnt = ++cnter[i];

            if (cnt > opt.first) {
                opt = make_pair(cnt, i);
            } else if (cnt == opt.first && i < opt.second) {
                opt = make_pair(cnt, i);
            }
        }
        return opt.second;
    }
};