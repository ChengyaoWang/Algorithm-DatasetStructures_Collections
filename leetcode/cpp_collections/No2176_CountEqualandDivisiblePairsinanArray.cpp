# include <vector>
# include <map>

using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
       
        int cul = 0;
        unordered_map<int, vector<int>> cnter = {};

        for (int i = 0; i < nums.size(); ++i) {
            for (auto &j: cnter[nums[i]]) {
                if ((i * j) % k == 0) {
                    ++cul;
                }
            }
            cnter[nums[i]].push_back(i);
        }

        return cul;
    }
};