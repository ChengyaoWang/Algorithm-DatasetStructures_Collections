# include <queue>
# include <vector>
# include <algorithm>
# include <unordered_map>
using namespace std;

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        
        int ret = 0, n = values.size();

        vector<pair<int, int>> vec;
        for (int i = 0; i < n; ++i) 
            vec.emplace_back(values[i], labels[i]);
        
        sort(vec.begin(), vec.end(),
            [](const pair<int, int>& i, const pair<int, int>& j){
                return i.first > j.first;
            }
        );

        unordered_map<int, int> lim;

        for (
            int gbl_cnt = 0, ptr = 0;
            gbl_cnt < numWanted && ptr < n;
            ptr++
        ) {
            auto elem = vec[ptr];
            if (++lim[elem.second] > useLimit)
                continue;

            ret += elem.first;
            ++gbl_cnt;
        }

        return ret;
    }
};