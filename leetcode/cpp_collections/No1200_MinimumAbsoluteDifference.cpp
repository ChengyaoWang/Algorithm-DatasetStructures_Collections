# include <vector>
# include <numeric>
# include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {

        vector<vector<int>> ret;

        sort(arr.begin(), arr.end());
        int optMin = numeric_limits<int>::max() >> 2;
        int lastElem = numeric_limits<int>::min() >> 2;

        for (auto& i: arr) {
            auto gap = i - lastElem;
            if (gap <= optMin) {
                if (gap < optMin) {
                    ret.clear();
                }
                ret.emplace_back(lastElem, i);
                optMin = gap;
            }
            lastElem = i;
        }
        return ret;        
    }
};