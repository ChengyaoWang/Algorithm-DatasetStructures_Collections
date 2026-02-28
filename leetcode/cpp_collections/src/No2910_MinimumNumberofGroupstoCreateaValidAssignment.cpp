# include <vector>
# include <limits>
# include <unordered_map>
using namespace std;

class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& balls) {

        unordered_map<int, int> cnter;
        for (auto &i: balls)
            ++cnter[i];
        vector<int> cnterSet;
        for (auto &i: cnter)
        cnterSet.push_back(i.second);
        
        int ret = numeric_limits<int>::max();
        int minElem = *min_element(cnterSet.begin(), cnterSet.end());

        for (int binS = 1; binS <= minElem; ++binS) {
            int sum_of_bins = 0;
            for (auto &i: cnterSet) {
                int a = i / (binS + 1);
                int b = i % (binS + 1);
                if (b == 0) {
                    sum_of_bins += a;
                }
                else if ((binS - b) <= a) {
                    sum_of_bins += a + 1;
                }
                else {
                    sum_of_bins = numeric_limits<int>::max();
                    break;
                }
            }
            ret = min(ret, sum_of_bins);
        }
        return ret;
    }
};