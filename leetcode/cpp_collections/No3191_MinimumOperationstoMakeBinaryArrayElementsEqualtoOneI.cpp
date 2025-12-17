# include <vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int i = 0, ops = 0;
        while(i < nums.size()) {
            if (nums[i] == 0) {
                for (int j = 0; j < 3; ++j) {
                    if((i + j) < nums.size()) {
                        nums[i + j] = 1 - nums[i + j];
                    }
                    else {
                        return -1;
                    }
                }
                ++ops;
            }
            ++i;
        }

        return ops;
    }
};