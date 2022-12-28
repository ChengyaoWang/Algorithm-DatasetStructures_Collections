# include <vector>

using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        
        vector<bool> seen(k + 1, false);
        int i = 0, cnter = 0;

        for (cnter = 0;; ++cnter) {
            i %= k;
            if (seen[i]) {
                break;
            }
            seen[i] = true;
            i = 10 * i + 1;
        }

        return i == 0 ? cnter: -1;
    }
};