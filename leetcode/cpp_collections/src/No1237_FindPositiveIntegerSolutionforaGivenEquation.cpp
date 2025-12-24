# include <vector>

using namespace std;

class CustomFunction {
public:
    int f(int x, int y);
};

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {

        int low, mid, up = 1001;
        vector<vector<int>> res = {};
        for (int x = 1; x <= 1000; ++x) {
            
            low = 1;
            // Binary Search
            while (low < up) {
                mid = (low + up) / 2;
                if (customfunction.f(x, mid) == z) {
                    low = mid;
                    break;
                } else if (customfunction.f(x, mid) < z) {
                    low = mid + 1;
                } else {
                    up = mid;
                }
            }

            // After Binary Search is Over
            if (customfunction.f(x, low) == z) {
                res.push_back({x, low});
            }
            up = low + 1;
        }
        return res;
    }
};