# include <vector>
# include <algorithm>
# include <numeric>
# include <functional>
using namespace std;

class Solution {
private:
    int d;
    vector<int> matchsticks;
public:
    bool makesquare(vector<int>& matchsticks) {
        d = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (d % 4 != 0) return false;
        d /= 4;
        this -> matchsticks = matchsticks;
        sort((this -> matchsticks).begin(), (this -> matchsticks).end(), greater<int>());
        vector<int> sofar(4, 0);
        return dfsHelper(sofar, 0);
    }

    bool dfsHelper(vector<int> sofar, int depth) {
        if (depth == matchsticks.size()) {
            return all_of(sofar.begin(), sofar.end(), [=](int i){
                return i == d;
            });
        }

        bool res = false;
        sort(sofar.begin(), sofar.end());
        for (int i = 0; i < 4; ++i) {
            if (i > 0 && sofar[i] == sofar[i - 1])  continue;
            sofar[i] += matchsticks[depth];
            if (sofar[i] <= d) {
                res |= dfsHelper(sofar, depth + 1);
                if (res)    break;
            }
            sofar[i] -= matchsticks[depth];
        }
        return res;
    }
};