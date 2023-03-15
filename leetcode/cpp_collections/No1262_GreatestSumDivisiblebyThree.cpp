# include <vector>
using namespace std;

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        
        int totalSum = 0;
        pair<int, int> re1 = make_pair(100000, 100001);
        pair<int, int> re2 = make_pair(100000, 100001);
        for (auto& i: nums) {
            totalSum += i;
            if (i % 3 == 1) {
                if (i < re1.second)
                    re1.second = i;
                if (i < re1.first)
                    swap(re1.first, re1.second);
            }
            if (i % 3 == 2) {
                if (i < re2.second)
                    re2.second = i;
                if (i < re2.first)
                    swap(re2.first, re2.second);
            }
        }

        int sub = 0;
        if (totalSum % 3 == 1)
            sub = min(re1.first, re2.first + re2.second);
        if (totalSum % 3 == 2)
            sub = min(re2.first, re1.first + re1.second);
        return totalSum - sub;
    }
};