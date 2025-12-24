# include <vector>
using namespace std;

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {

        auto l = left.empty() ? 0: *max_element(left.begin(), left.end());
        auto r = right.empty() ? n: *min_element(right.begin(), right.end());
        return max(l, n - r);
    }
}; 