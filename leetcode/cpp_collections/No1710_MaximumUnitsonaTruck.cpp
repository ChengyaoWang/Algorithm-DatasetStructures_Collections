# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort(boxTypes.begin(), boxTypes.end(), 
            [](vector<int> a, vector<int> b){
                return a[1] > b[1];
            }
        );
        
        int ret = 0;
        for (auto& i: boxTypes) {
            ret += i[1] * min(truckSize, i[0]);
            truckSize -= min(truckSize, i[0]);
            if (truckSize == 0)
                break;
        }

        return ret;
    }
};