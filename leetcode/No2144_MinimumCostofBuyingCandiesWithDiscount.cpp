# include <vector>
# include <algorithm>
# include <functional>

using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());
        int total_cost = 0;
        
        for (int i = 0; i < cost.size(); ++i) {
            if (i % 3 != 2) {
                total_cost += cost[i];
            }
        }

        return total_cost;
    }
};