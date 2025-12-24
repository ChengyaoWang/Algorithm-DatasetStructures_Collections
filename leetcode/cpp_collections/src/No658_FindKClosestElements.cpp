# include <vector>
# include <queue>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        auto hi = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        auto lo = hi - 1;

        vector<int> ret;
        deque<int> q;

        while (q.size() < k) {
            
            if (hi == arr.size()) {
                q.push_front(arr[lo--]);
            } else if (lo == -1) {
                q.push_back(arr[hi++]);
            } else {
                if (abs(x - arr[hi]) < abs(x - arr[lo])) {
                    q.push_back(arr[hi++]);
                } else {
                    q.push_front(arr[lo--]);
                }
            }
        }

        while (!q.empty()) {
            ret.push_back(q.front());
            q.pop_front();
        }

        return ret;
    }
};