# include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lo = 0, hi = numbers.size() - 1;
        
        for (;;) {
            auto sum = numbers[lo] + numbers[hi];
            if (sum == target)  break;
            else if (sum < target) ++lo;
            else --hi;
        }

        return vector<int>{lo + 1, hi + 1};
    }
};