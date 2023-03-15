# include <string>
# include <vector>
using namespace std;

class Solution {
public:
    int minimumTime(string s) {
        int cumSum = 0;
        int maxSub = 0, maxSubSum = s.size();
        for (auto& c: s) {
            cumSum += (c == '1') ? 1: -1;
            maxSub = max(maxSub, cumSum);
            maxSubSum = min(maxSubSum, cumSum - maxSub);
        }
        return s.size() + maxSubSum;
    }
};