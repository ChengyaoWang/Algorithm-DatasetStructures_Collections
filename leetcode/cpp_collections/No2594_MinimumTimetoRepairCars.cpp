# include <vector>
# include <numeric>
# include <math.h>
using namespace std;

class Solution {
public:
    bool isBeDone(long long t, int cars, vector<int>& ranks) {

        auto accum = 0LL;
        for (auto& i: ranks) {
            accum += (long long)sqrt(double(t) / (double)i);
        };

        return accum >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {

        long long mx = *max_element(ranks.begin(), ranks.end());
        long long low = 0, up = mx * cars * cars;
        
        while (low < up) {
            auto mid = (low + up) / 2;
            if (isBeDone(mid, cars, ranks)) {
                low = mid;
            } else {
                up = mid - 1;
            }
        }

        return low;        
    }
};