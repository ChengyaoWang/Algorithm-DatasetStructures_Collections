# include <vector>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        vector<bool> isSeen(10001);
        for (auto &i: nums) {
            if (isSeen[i])  return i;
            isSeen[i] = true;
        }
        return -1;        
    }
};