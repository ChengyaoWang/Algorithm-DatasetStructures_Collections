# include <vector>
# include <map>
using namespace std;

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> cnter = {};
        for (auto elem: nums)
            ++cnter[elem];

        for (auto it = cnter.begin(); it != cnter.end(); ++it) {
            if (it -> second == 0)
                continue;
            auto st_num = it -> first;
            for (int i = st_num + 1; i < st_num + k; ++i) {
                if ((cnter.find(i) == cnter.end()) || (cnter[i] < it -> second))
                    return false;
                cnter[i] -= it -> second;
            }
        }

        return true;
    }
};