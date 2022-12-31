# include <vector>
# include <unordered_map>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> cnter = {};
        int res = 0;
        for (auto i: nums) {
            if (k == 0) {
                res += (cnter[i] == 1);
            } else if (cnter[i] == 0) {
                res += (cnter[i - k] > 0);
                res += (cnter[i + k] > 0);
            }
            ++cnter[i];
        }
        return res;
    }
};