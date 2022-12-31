# include <vector>
# include <string>
# include <numeric>
# include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> elem2idx = {};
        for (int i = 0; i < list1.size(); ++i) {
            if (elem2idx.find(list1[i]) == elem2idx.end())
                elem2idx[list1[i]] = i;
        }

        int idxSum = numeric_limits<int>::max();
        vector<string> ret = {};
        for (int i = 0; i < list2.size(); ++i) {
            if (elem2idx.find(list2[i]) != elem2idx.end()) {
                int tmp = i + elem2idx[list2[i]];
                if (tmp < idxSum) {
                    ret.clear();
                    idxSum = tmp;
                }
                if (tmp <= idxSum) {
                    ret.push_back(list2[i]);
                }
            }
        }
        return ret;
    }
};