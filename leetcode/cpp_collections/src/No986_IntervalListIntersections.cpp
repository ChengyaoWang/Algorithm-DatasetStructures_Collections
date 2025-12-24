# include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(
        vector<vector<int>>& firstList,
        vector<vector<int>>& secondList
    ) {
        
        int sofar = -1, i = 0, j = 0;
        vector<int> next;
        vector<vector<int>> ret;

        while (i < firstList.size() || j < secondList.size()) {
            
            if (j == secondList.size() || (i < firstList.size() && firstList[i][0] < secondList[j][0])) {
                next = firstList[i++];
            } else if (j < secondList.size()){
                next = secondList[j++];
            }

            if (next[0] <= sofar) {
                ret.push_back({next[0], min(sofar, next[1])});
            }

            sofar = max(sofar, next[1]);
        }

        return ret;
    }
};