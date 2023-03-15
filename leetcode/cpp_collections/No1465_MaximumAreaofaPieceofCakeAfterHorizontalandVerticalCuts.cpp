# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        int maxH = -1, maxW = -1;
        int prevH = 0, prevW = 0;
        for (auto& i: horizontalCuts) {
            maxH = max(maxH, i - prevH);
            prevH = i;
        }
        for (auto& i: verticalCuts) {
            maxW = max(maxW, i - prevW);
            prevW = i;
        }
        

        return (long long)(maxH) * maxW % 1000000007;
    }
};