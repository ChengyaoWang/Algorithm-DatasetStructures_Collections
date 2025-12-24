# include <vector>
# include <numeric>
# include <algorithm>
# include <functional>

using namespace std;

class Solution {
public:
    long long maximumBeauty(
        vector<int>& flowers, 
        long long newFlowers, 
        int target, int full, int partial
    ) {

        for (auto &i: flowers)  i = min(i, target);
        sort(flowers.begin(), flowers.end());

        long long N = flowers.size();
        // Corner Cases
        if (flowers[0] == target)   return N * full;
        if (newFlowers >= target * N - accumulate(flowers.begin(), flowers.end(), 0LL))
            return max(N * full, (N - 1) * full + (long long)(target - 1) * partial);

        // Build Cost Array, Its Monotonically Increasing
        vector<long long> cost = {0};
        for (int i = 1; i < N; ++i)
            cost.push_back(cost.back() + i * (flowers[i] - flowers[i - 1]));

        // Start Iterating
        long long k = N, res = 0, flowersRemaining = newFlowers;
        
        while (k > 0 && flowers[k - 1] == target)
            --k;

        while (flowersRemaining >= 0) {

            auto j = upper_bound(cost.begin(), cost.begin() + k, flowersRemaining) - cost.begin();
            --j;

            int delta_h = (flowersRemaining - cost[j]) / (j + 1);
            res = max(res, (N - k) * full + min(flowers[j] + delta_h, target - 1) * (long long)partial);

            if (--k == -1)    break;
            flowersRemaining -= (target - flowers[k]);
        }

        return res;
    }
};