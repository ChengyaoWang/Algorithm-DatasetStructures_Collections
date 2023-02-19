# include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        for (int i = 0; i < nums.size(); ++i) {
            auto elem = abs(nums[i]) - 1;
            if (nums[elem] > 0)
                nums[elem] *= -1;
        }

        vector<int> ret;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0)
                ret.push_back(i + 1);
        }
        return ret;
    }
};