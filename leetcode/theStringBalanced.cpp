# include <string>

using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int gap = 0, res = 0;
        for (auto i: s) {
            gap += (i == '[') ? 1: -1;

            if (gap < 0) {
                res -= gap++;
            }
        }
        return gap;
    }
};