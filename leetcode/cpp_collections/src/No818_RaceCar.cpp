# include <vector>
# include <numeric>
using namespace std;

class Solution {
public:
    vector<int> optSteps;

    int recurHelper(int target) {
        
        int& res = optSteps[target];
        if (res != numeric_limits<int>::max()) {
            return res;
        }

        int i = 32 - __builtin_clz(target);
        if ((target + 1) == (1 << i)) {
            res = i;
        } else {
            res = recurHelper((1 << i) - 1 - target) + i + 1;
            for (int j = 0; j < i; ++j) {
                res = min(
                    res,
                    recurHelper(target - (1 << (i - 1)) + (1 << j)) + i + j + 1
                );
            }
        }

        return res;
    }

    int racecar(int target) {

        vector<int> optSteps(20001, numeric_limits<int>::max());
        this -> optSteps = move(optSteps);

        return recurHelper(target);
    }
};