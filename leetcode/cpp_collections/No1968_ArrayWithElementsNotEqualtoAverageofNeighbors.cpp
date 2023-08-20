# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        vector<int> ret;

        bool flag = false;
        int i = 0, j = nums.size() - 1;
        while (i <= j) {
            if (flag) {
                ret.push_back(nums[i++]);
            } else {
                ret.push_back(nums[j--]);
            }
            flag = !flag;
        }

        return ret;
    }
};