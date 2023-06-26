# include <vector>
# include <numeric>
using namespace std;

class Solution {
public:
    int findClosestNumber(vector<int>& nums) {

        int minDis = numeric_limits<int>::max();
        int retNum = numeric_limits<int>::max();

        for (auto& elem: nums) {
            if (abs(elem) < minDis) {
                minDis = abs(elem);
                retNum = elem;
            } else if (abs(elem) == minDis) {
                retNum = max(retNum, elem);
            }
        }

        return retNum;
    }
};