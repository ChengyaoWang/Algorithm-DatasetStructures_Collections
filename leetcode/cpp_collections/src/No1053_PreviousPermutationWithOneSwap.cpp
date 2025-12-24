# include <vector>
# include <limits>
# include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int curMin = numeric_limits<int>::max();
        unordered_map<int, int> map;
        
        for (int i = arr.size() - 1; i > -1; --i) {
            if (arr[i] > curMin) {
                auto elem = arr[i];
                for (int j = elem - 1; j > -1; --j) {
                    if (map.find(j) != map.end()) {
                        swap(arr[i], arr[map[j]]);
                        return arr;
                    }
                }
            } else {
                curMin = arr[i];
                map[arr[i]] = i;
            }
        }

        return arr;
    }
};