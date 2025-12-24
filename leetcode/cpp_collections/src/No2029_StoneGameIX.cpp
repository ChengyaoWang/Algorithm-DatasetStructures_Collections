# include <vector>
using namespace std;

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> cnter(3);
        for (auto& i: stones) {
            ++cnter[i % 3];
        }

        bool flag = cnter[0] % 2 == 1;
        return abs(cnter[1] - cnter[2]) > 0 ^ flag;
    }
};