# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sortedNum(nums.begin(), nums.end()), ret = {};
        sort(sortedNum.begin(), sortedNum.end());
    
        vector<int>::iterator di;
        for (auto i: nums) {
            di = lower_bound(sortedNum.begin(), sortedNum.end(), i);
            ret.push_back(di - sortedNum.begin());
        }

        return ret;        
    }
};