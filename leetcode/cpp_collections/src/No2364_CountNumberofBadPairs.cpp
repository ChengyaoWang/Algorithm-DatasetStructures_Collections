# include <vector>
# include <unordered_map>
using namespace std;

typedef long long ll;
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> cnter;
        ll n = nums.size(), totalN = 0;
        for (int i = 0; i < nums.size(); ++i) {
            totalN += cnter[i - nums[i]]++;
        }
        return n * (n - 1) / 2 - totalN;
    }
};