# include <vector>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 0, maxElem = -1;
        for (int i = 0; i < arr.size(); ++i) {
            maxElem = max(maxElem, arr[i]);
            res += maxElem == i;
        }        
        return res;
    }
};