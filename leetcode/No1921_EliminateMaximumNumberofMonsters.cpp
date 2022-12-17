# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        
        vector<double> eta = {};
        for (int i = 0; i < dist.size(); ++i) {
            eta.push_back(double(dist[i]) / speed[i]);
        }
        sort(eta.begin(), eta.end());

        int cnt = 1;
        double time = 1.;
        for (; cnt < eta.size(); ++cnt) {
            if (eta[cnt] <= time) {
                break;
            }
            time += 1.;
        }
        return cnt;
    }
};