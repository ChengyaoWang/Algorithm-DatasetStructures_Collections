# include <vector>
using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& candidates) {

        int ret = -1;
        for (int i = 0; i < 32; ++i) {
            auto cnter = 0;
            for (auto& num: candidates) {
                cnter += (num >> i & 1) == 1;
            }
            ret = max(ret, cnter);
        }

        return ret;
    }
};