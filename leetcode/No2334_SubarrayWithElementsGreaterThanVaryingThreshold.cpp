# include <vector>

using namespace std;

class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        
        vector<pair<int, int>> s = {{-1, -1}};
        nums.push_back(0);
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > threshold) return 1;
            while (nums[i] < s.back().second) {
                auto elem = s.back(); s.pop_back();
                if (threshold / (i - s.back().first - 1) < elem.second) {
                    return i - s.back().first - 1;
                }
            }
            s.push_back({i, nums[i]});
        }
        return -1;
        
    }
};