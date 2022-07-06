# include <vector>
# include <unordered_map>

class Solution {
private:
    int atMostKDistinct(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> map;
        int cnt = 0;
        
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            ++map[nums[i]];
            while (map.size() > k) {
                if (--map[nums[j]] == 0) {
                    map.erase(nums[j]);
                }
                ++j;
            }
            cnt += i - j + 1;
        }
        return cnt;
    }
public:
    int subarraysWithKDistinct(std::vector<int>& nums, int k) {
        return atMostKDistinct(nums, k) - atMostKDistinct(nums, k - 1);
   }
};