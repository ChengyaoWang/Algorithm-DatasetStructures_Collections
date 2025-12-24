# include <vector>
# include <limits>

using namespace std;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int i = 0, j = arr.size() - 1;
        int tmp = numeric_limits<int>::min();
        while (i < arr.size() && arr[i] >= tmp) {
            tmp = arr[i++];
        }

        tmp = numeric_limits<int>::max();
        while (j > i && arr[j] <= tmp) {
            tmp = arr[j--];
        }

        int ans = numeric_limits<int>::min();
        // Merge Results - From Left
        int ii = 0, jj = j + 1;
        for (; ii < i; ++ii) {
            while (jj < arr.size() && arr[ii] > arr[jj]) {
                ++jj;
            }
            ans = max(ans, ii + 1 + int(arr.size()) - jj);
        }
        // Merge Results - From Right
        ii = i - 1;
        jj = arr.size() - 1;
        
        for (; jj > j; --jj) {
            while (ii >= 0 && arr[ii] > arr[jj]) {
                --ii;
            }
            ans = max(ans, ii + 1 + int(arr.size()) - jj);
        }

        return arr.size() - ans;
    }
};