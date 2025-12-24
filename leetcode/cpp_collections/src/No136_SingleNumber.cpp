# include <vector>
# include <numeric>
# include <algorithm>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return accumulate(
            nums.begin(), nums.end(), 0, [](int &res, int a){
                return res ^ a;
            }
        );
    }
};