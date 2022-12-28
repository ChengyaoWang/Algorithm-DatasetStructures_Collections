# include <vector>
using namespace std;

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int l = 0, r = 1000000007;
        while (l < r) {
            auto mid = (l + r + 1) / 2;
            long long sum = 0;
            for (auto i: candies)
                sum += i / mid;
            if (k > sum)
                r = mid - 1;
            else
                l = mid;
        }
        return l;
    }
};