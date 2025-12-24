# include <vector>
# include <unordered_set>
using namespace std;

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int N = l.size(), maxElem, minElem, gap;
        unordered_set<int> set = {};

        vector<bool> ret = {};
        for (int i = 0; i < N; ++i) {
            maxElem = *max_element(nums.begin() + l[i], nums.begin() + r[i] + 1);
            minElem = *min_element(nums.begin() + l[i], nums.begin() + r[i] + 1);
            if (maxElem == minElem) {
                ret.push_back(true);
                continue;
            } else if ((maxElem - minElem) % (r[i] - l[i]) != 0) {
                ret.push_back(false);
                continue;
            }
            gap = (maxElem - minElem) / (r[i] - l[i]);
            for (int j = l[i]; j <= r[i]; ++j) {
                if ((nums[j] - minElem) % gap != 0) {
                    break;
                }
                set.insert((nums[j] - minElem) / gap);
            }

            ret.push_back(set.size() == (r[i] - l[i] + 1));
            set.clear();
        }

        return ret;
    }
};