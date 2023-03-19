# include <vector>
# include <numeric>
# include <unordered_map>
using namespace std;

class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {

        unordered_map<int, pair<int, int>> m;

        int maxCnt = -1, retVal = numeric_limits<int>::max();
        for (auto& i: nums) {

            if (m.find(i % space) == m.end())
                m[i % space] = make_pair(0, numeric_limits<int>::max());

            pair<int, int>& tmp = m[i % space];
            tmp.first += 1;
            tmp.second = min(tmp.second, i);

            if (tmp.first > maxCnt || (
                tmp.first == maxCnt && tmp.second < retVal
            )) {
                maxCnt = tmp.first;
                retVal = tmp.second;
            }
        }
        return retVal;
    }
};