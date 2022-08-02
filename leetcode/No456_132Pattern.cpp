# include <vector>

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        vector<int> s;
        int mid = ~ __INT_MAX__;

        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] < mid) {
                return true;
            }
            while (!nums.empty() && nums[i] > nums.back()) {
                mid = nums.back();
                nums.pop_back();
            }
            nums.push_back(nums[i]);
        }
        return false;
    }
};