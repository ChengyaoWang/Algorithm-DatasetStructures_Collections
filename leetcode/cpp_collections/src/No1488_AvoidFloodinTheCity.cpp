# include <queue>
# include <vector>
# include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        
        vector<int> nextOccurence(rains.size(), rains.size());
        unordered_map<int, int> idxMem = {};
        for (int i = rains.size() - 1; i >= 0; --i) {
            auto elem = rains[i];
            if (idxMem.find(elem) != idxMem.end()) {
                nextOccurence[i] = idxMem[elem];
            }
            idxMem[elem] = i;
        }

        vector<int> ans(rains.size(), 1);
        auto cmp = [&](int i, int j) {
            return nextOccurence[i] > nextOccurence[j];
        };
        priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
        
        for (int i = 0; i < rains.size(); ++i) {
            auto elem = rains[i];
            if (elem == 0) {
                if (!q.empty()) {
                    ans[i] = rains[q.top()];
                    q.pop();
                }
            } else {
                if (!q.empty() && nextOccurence[q.top()] == i) {
                    return vector<int>(0);
                }
                q.push(i);
                ans[i] = -1;
            }
        }

        return ans;
    }
};