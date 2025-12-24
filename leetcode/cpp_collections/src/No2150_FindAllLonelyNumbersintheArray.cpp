# include <vector>
# include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> cnter;

        for (auto &i: nums) {
            ++cnter[i];
            cnter[i - 1] = -2147483647 - 1;
            cnter[i + 1] = -2147483647 - 1;
        }

        vector<int> retList;
        for (auto &i: cnter) {
            if (i.second == 1) {
                retList.push_back(i.first);
            }
        }

        return retList;
    }
};