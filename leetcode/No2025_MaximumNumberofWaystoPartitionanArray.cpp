# include <vector>
# include <unordered_map>

using namespace std;

class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        int sum = 0;
        for (auto &i: nums) {
            sum += i;
        }

        int runsumL = 0;
        unordered_map<int, int> L, R;
        for (auto &i: nums) {
            runsumL += i;
            ++R[2 * runsumL - sum];
        }

        int ans = R[0], d, runsumL;
        for (auto &i: nums) {
            d = K - i;
            ans = max(ans, L[d] + R[-d]);

            runsumL += i;
            ++L[2 * runsumL - sum];
            --R[2 * runsumL - sum];
        }

        return ans;
    }
};