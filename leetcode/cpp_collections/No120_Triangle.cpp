# include <vector>
# include <numeric>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> arr(n, numeric_limits<int>::max());
        arr[0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            arr[i] = arr[i - 1] + triangle[i][i];
            for (int j = i - 1; j > 0; --j) {
                arr[i] = triangle[i][j] + min(arr[i], arr[i - 1]);
            }
            arr[0] = arr[0] + triangle[i][0];
        }

        return *min_element(arr.begin(), arr.end());
    }
};