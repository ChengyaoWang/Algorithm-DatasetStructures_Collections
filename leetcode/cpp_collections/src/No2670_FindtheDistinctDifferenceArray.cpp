# include <vector>
# include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {

        unordered_map<int, int> cnter_fwd, cnter_bwd;
        for (auto& i: nums)
            ++cnter_fwd[i];

        vector<int> ret;
        for (auto& i: nums) {
            if (--cnter_fwd[i] == 0) {
                cnter_fwd.erase(i);
            }
            ++cnter_bwd[i];
            ret.push_back(cnter_fwd.size() - cnter_bwd.size());
        }

        return ret;        
    }
};