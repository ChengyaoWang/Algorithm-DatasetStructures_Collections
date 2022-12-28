# include <vector>
# include <limits>
using namespace std;


class Solution {
public:
    bool check(vector<int>& nums) {
        bool rotate_point = false;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1]) {
                if (rotate_point)   return false;
                rotate_point = true;
            }
        }
        return !rotate_point | (nums.front() >= nums.back());
    }
};