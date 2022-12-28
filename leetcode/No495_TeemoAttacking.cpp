# include <vector>
using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        
        int res = duration;
        for (int i = 0; i < timeSeries.size() - 1; ++i) {
            res += min(timeSeries[i + 1] - timeSeries[i], duration);
        }

        return res;
    }
};