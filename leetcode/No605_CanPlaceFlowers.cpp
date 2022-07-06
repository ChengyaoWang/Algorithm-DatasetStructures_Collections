# include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int retCnt = 0, cumCnt = 1;
        for (auto& i: flowerbed) {
            if (i == 1) {
                retCnt += max((cumCnt - 2) / 2, 0);
                cumCnt = 0;
            } else {
                ++cumCnt;
            }
        }
        return retCnt >= n;
    }
};