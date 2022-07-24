# include <vector>

using namespace std;

class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        if (maxDoubles == 0 || target == 1) {
            return target - 1;
        } else if (target % 2 == 1) {
            return 1 + minMoves(target - 1, maxDoubles);
        } else {
            return 1 + minMoves(target / 2, maxDoubles - 1);
        }
    }
};