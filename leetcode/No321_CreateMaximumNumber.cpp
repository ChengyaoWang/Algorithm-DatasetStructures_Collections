# include <vector>
# include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> retList(k, 0);

        for (int i = max(0, k - int(nums2.size())); i <= min(k, int(nums1.size())); ++i) {
            auto tmp = merge(maxSingleNum(nums1, i), maxSingleNum(nums2, k - i));
            if (compare(retList, tmp)) {
                retList = tmp;
            }
        }
        return retList;    }

    bool compare(vector<int> nums1, vector<int> nums2) {
        for (int i = 0; i < nums1.size(); ++i) {
            if (nums1[i] != nums2[i]) {
                return nums1[i] < nums2[i];
            }
        }
        return false;
    }

    vector<int> maxSingleNum(vector<int> num, int k) {
        vector<int> maxNum;
        for (int i = 0; i < num.size(); ++i) {
            while (
                (!maxNum.empty()) &&
                (maxNum.back() < num[i]) &&
                ((k - maxNum.size()) < (num.size() - i))
            ) {
                maxNum.pop_back();
            }

            if (maxNum.size() < k) {
                maxNum.push_back(num[i]);
            }            
        }
        return maxNum;
    }

    vector<int> merge(vector<int> nums1, vector<int> nums2) {
        vector<int> mergedNum;
        int i = 0, j = 0;
        while (nums1.size() + nums2.size()) {
            if (nums1 < nums2) {
                mergedNum.push_back(nums2[0]);
                nums2.erase(nums2.begin());
            } else {
                mergedNum.push_back(nums1[0]);
                nums1.erase(nums1.begin());                
            }
        }
        return mergedNum;
    }
};