# include <vector>
using namespace std;

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> mem(101, 0);
        for (auto& i: logs) {
            ++mem[i[0] - 1950];
            --mem[i[1] - 1950];
        }
        int optVal = -1, optYear = -1;
        int runningSum = -1;
        for (int i = 0; i < mem.size(); ++i) {
            runningSum += mem[i];
            if (optVal < runningSum) {
                optVal = max(optVal, runningSum);
                optYear = i;
            }
        }
        return optYear + 1950;
    }
};