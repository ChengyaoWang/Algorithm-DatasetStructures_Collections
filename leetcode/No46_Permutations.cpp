# include <vector>
# include <unordered_map>

using namespace std;


class Solution {
public:
    unordered_map<int, int> cnter;
    vector<vector<int>> result;
    vector<vector<int>> permute(vector<int>& nums) {
        cnter = {};
        result = {};
        for (auto &i: nums) ++cnter[i];

        helper_func(nums.size(), vector<int>{}, nums);
        return result;
    }

    
    void helper_func(
        int n,
        vector<int> pathSoFar,
        vector<int> nums
    ) {
        if (pathSoFar.size() == n) {
            result.push_back(pathSoFar);
            return;
        }

        for (int i = 0; i < n; ++i) {
            auto elem = nums[i];
            if (cnter[elem] > 0) {
                --cnter[elem];
                pathSoFar.push_back(elem);
                helper_func(n, pathSoFar, nums);
                pathSoFar.pop_back();
                ++cnter[elem];
            }
        }

    }
};