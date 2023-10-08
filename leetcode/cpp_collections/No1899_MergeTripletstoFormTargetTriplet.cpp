# include <vector>
# include <numeric>
# include <algorithm>
using namespace std;

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
    
        vector<int> init = {1, 1, 1};

        return accumulate(
            triplets.begin(), triplets.end(), init,
            [&](const vector<int>& a, const vector<int>& b){
                if (b[0] > target[0] || b[1] > target[1] || b[2] > target[2]) {
                    return a;
                }
                return vector<int>{max(a[0], b[0]), max(a[1], b[1]), max(a[2], b[2])};
            }
        ) == target;
    }
};