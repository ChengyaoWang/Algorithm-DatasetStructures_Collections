# include <vector>
# include <queue>
using namespace std;

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        
        if (k >= arr.size())
            return *max_element(arr.begin(), arr.end());
        
        int curMax = arr[0], combo = 0;
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] > curMax) {
                curMax = arr[i];
                combo = 0;
            }
            if (++combo == k)
                break;

        }

        return curMax;
    }
};