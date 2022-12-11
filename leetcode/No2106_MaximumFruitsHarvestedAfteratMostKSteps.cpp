# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        // First Insert Initial Position
        auto insLoc = lower_bound(
            fruits.begin(), fruits.end(), startPos,
            [](vector<int> a, int b){ return a[0] < b; }
        );
        int initLoc = insLoc - fruits.begin();
        fruits.insert(insLoc, vector<int> {startPos, 0});
        
        vector<int> cumSum = {0};
        for (auto elem: fruits) {
            cumSum.push_back(cumSum.back() + elem[1]);
        }

        int res = 0, cost;
        auto costCal = [fruits, initLoc](int i, int j){
            int cost = fruits[j][0] - fruits[i][0];
            cost += min(fruits[j][0] - fruits[initLoc][0], fruits[initLoc][0] - fruits[i][0]);            
            return cost;
        };
    
        for (int i = 0, j = initLoc; j < fruits.size(); ++j) {
            cost = costCal(i, j);
            while (i < initLoc && k < cost) {
                cost = costCal(++i, j);
            }

            if (cost <= k)
                res = max(res, cumSum[j + 1] - cumSum[i]);
        }
        
        return res;
    }


};