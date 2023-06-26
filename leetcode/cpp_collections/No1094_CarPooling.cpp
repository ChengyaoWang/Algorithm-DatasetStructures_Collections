# include <vector>
# include <queue>
# include <algorithm>
# include <numeric>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        vector<int> idx(trips.size());
        iota(idx.begin(), idx.end(), 0);

        sort(idx.begin(), idx.end(),
            [&](const int &i, const int &j) {
                if (trips[i][1] == trips[j][1])
                    return trips[i][2] < trips[j][2];
                return trips[i][1] < trips[j][1];
            }
        );
    
        auto lessF = [&](const int &i, const int &j) {
            return trips[i][2] > trips[j][2];
        };
        priority_queue<int, vector<int>, decltype(lessF)> pq(lessF);
        int totalLoad = 0;
        for (auto i: idx) {
            while (!pq.empty() && trips[pq.top()][2] <= trips[i][1]) {
                auto elem = pq.top();
                pq.pop();
                totalLoad -= trips[elem][0];
            }

            pq.push(i);
            totalLoad += trips[i][0];
            if (totalLoad > capacity) {
                return false;
            }
        }
        return true;   
    }
};