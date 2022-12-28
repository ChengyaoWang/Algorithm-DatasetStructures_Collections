# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int elem = 0;
        for (auto i: arr) {
            elem += min(i - elem, 1);
        }

        return elem;
    }
};