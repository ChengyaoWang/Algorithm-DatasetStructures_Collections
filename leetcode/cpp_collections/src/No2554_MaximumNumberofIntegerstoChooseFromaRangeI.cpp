# include <vector>
# include <unordered_set>
using namespace std;

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {

        unordered_set<int> mem = {};
        for (auto& i: banned)
            mem.insert(i);
        
        int sum = 0, cnter = 0;
        for (int i = 1; i <= n; ++i) {
            if (mem.find(i) != mem.end())
                continue;
            sum += i;
            if (sum > maxSum) {
                break;
            }
            ++cnter;
        }

        return cnter;
    }
};