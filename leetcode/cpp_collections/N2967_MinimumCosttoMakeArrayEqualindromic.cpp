# include <vector>
# include <string>
# include <algorithm>

using namespace std;

class Solution {
public:
    long long calculateCost(int x, vector<int>& nums) {
        long long ret = 0LL;
        for (auto &i: nums) {
            ret += abs((long long)i - x);
        }
        return ret;
    }

    int constructPanlindrome(int base, bool isOddLength, bool fill9) {

        int ret = base;
        if (isOddLength && !fill9)
            base /= 10;
        if (fill9)
            ret = ret * 10 + 9;

        while(base) {
            ret = ret * 10 + base % 10;
            base /= 10;
        }

        return ret;
    }

    long long generateTestCase(int medianInt, vector<int>& nums) {
        
        size_t t = to_string(medianInt).size();
        for(int i = 0; i < t / 2; ++i)
            medianInt /= 10;

        auto lofi = [](int inp){
            return to_string(inp).length();
        };

        int p1 = constructPanlindrome(medianInt, t % 2 != 0, false);
        int p2 = constructPanlindrome(
            medianInt - 1,
            (t % 2 != 0) != (lofi(medianInt) > lofi(medianInt - 1)),
            (t % 2 == 0) && (lofi(medianInt) > lofi(medianInt - 1) || medianInt == 1)
        );
        int p3 = constructPanlindrome(
            medianInt + 1,
            (t % 2 != 0) != (lofi(medianInt) < lofi(medianInt + 1)),
            false
        );

        return min(
            min(
                calculateCost(p1, nums),
                calculateCost(p2, nums)
            ),
            calculateCost(p3, nums)
        );
    }

    long long minimumCost(vector<int>& nums) {
        // Equilvalent to the nearest palindromic number to the median of the array
        
        size_t n = nums.size() / 2;
        nth_element(nums.begin(), nums.begin() + n, nums.end());
        int upper_median = nums[n], lower_median = nums[n];
        if (nums.size() % 2 == 0) {
            lower_median = * max_element(nums.begin(), nums.begin() + n);
        }
        double medianDBL = (lower_median + upper_median) / 2.;

        long long c1 = generateTestCase((int)floor(medianDBL), nums);
        long long c2 = generateTestCase((int)ceil(medianDBL), nums);

        return min(c1, c2);
    }
};