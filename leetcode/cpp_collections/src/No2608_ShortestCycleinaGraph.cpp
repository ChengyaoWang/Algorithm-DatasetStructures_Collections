# include <vector>
# include <limits>
# include <queue>

using namespace std;

class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> graph(n, vector<int>());
        for (auto &i: edges) {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }

        vector<int> mask(n, 0), ans(n, -1);
        queue<pair<int, int>> q;
        int ret = numeric_limits<int>::max();
        
        for (int i = 0; i < n; ++i) {
            q.push({i, 1});
            mask[i] = 1;

            while(!q.empty()) {
                auto elem = q.front();
                q.pop();
                
                for (auto &j: graph[elem.first]) {
                    if (j == ans[elem.first])
                        continue;
                    else if (mask[j] > 0) {
                        ret = min(ret, elem.second + mask[j] - 1);
                    } else {
                        mask[j] = elem.second + 1;
                        ans[j] = elem.first;
                        q.push({j, elem.second + 1});
                    }
                }
            }

            fill(mask.begin(), mask.end(), 0);
            fill(ans.begin(), ans.end(), -1);
        }
    
        return ret == numeric_limits<int>::max() ? -1: ret;
    }
};