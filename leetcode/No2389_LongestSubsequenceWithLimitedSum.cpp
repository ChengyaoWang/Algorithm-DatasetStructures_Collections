# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        nums.push_back(0);
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i)
            nums[i] += nums[i - 1];

        vector<int> ret = {};
        for (auto &i: queries) {
            auto it = upper_bound(nums.begin(), nums.end(), i);
            ret.push_back(it - nums.begin() - 1);
        }

        return ret;
    }
};