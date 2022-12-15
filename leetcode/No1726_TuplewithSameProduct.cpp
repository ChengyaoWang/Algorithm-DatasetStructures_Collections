# include <vector>
# include <unordered_map>
using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> cnter = {};
        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                int prod = nums[i] * nums[j];
                res += cnter[prod]++;
            }
        }
        return 8 * res;
    }
};