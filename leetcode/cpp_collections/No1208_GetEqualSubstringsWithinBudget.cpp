# include <string>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {

        int ret = 0;
        int cost = 0;
        int N = s.size(), lo = -1;

        for (int up = 0; up < N; ++up) {
            cost += abs(s[up] - t[up]);
            while (lo < up && maxCost < cost) {
                ++lo;
                cost -= abs(s[lo] - t[lo]);
            }
            ret = max(ret, up - lo);
        }
        return ret;
        
    }
};