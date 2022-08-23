# include <vector>
# include <algorithm>

using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> dummyArr(heights.size(), 0);
        copy(heights.begin(), heights.end(), dummyArr.begin());
        sort(dummyArr.begin(), dummyArr.end());

        int res = 0;
        for (int i = 0; i < heights.size(); ++i) {
            res += (heights[i] == dummyArr[i]);
        }
        
        return heights.size() - res;
    }
};