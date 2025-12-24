# include <vector>
using namespace std;

using ll = long long;

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int retMod = 1, cumMod = a % 1337, curMod;

        for (auto it = b.rbegin(); it != b.rend(); ++it) {
            curMod = cumMod;
            for (int i = 1; i < 10; ++i) {
                if (i == *it) {
                    retMod = (retMod * curMod) % 1337;
                }
                curMod = (curMod * cumMod) % 1337;
            }
            cumMod = curMod;
        }

        return retMod;
    }
};