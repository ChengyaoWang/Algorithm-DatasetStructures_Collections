# include <queue>
# include <vector>
# include <numeric>
# include <unordered_map>
# include <unordered_set>
using namespace std;

class Solution {
public:
    int checkWays(vector<vector<int>>& pairs) {

        priority_queue<pair<int, int>> pq;
        unordered_map<int, unordered_set<int>> adj;
        for (auto& p: pairs) {
            adj[p[0]].insert(p[1]);
            adj[p[1]].insert(p[0]);
        }

        for (auto& [k, v]: adj) {
            pq.push(make_pair(v.size(), k));
        }

        int ret = 1;
        unordered_set<int> visited;
        while (!pq.empty()) {

            auto [d, v] = pq.top();
            pq.pop();

            int parent = -1;
            int parentDegree = numeric_limits<int>::max();
            for (auto& tmpParent: adj[v]) {
                if (visited.count(tmpParent) == 0)
                    continue ;
                auto tmpParentDegree = adj[tmpParent].size();
                if (d <= tmpParentDegree && tmpParentDegree < parentDegree) {
                    parentDegree = tmpParentDegree;
                    parent = tmpParent;
                }
            }

            visited.insert(v);
            if (parent == -1) {
                if (d != adj.size() - 1) {
                    return 0;
                }
                continue ;
            }

            // Check If multiple parent exists
            for (auto& tmpNeighbor: adj[v]) {
                if (tmpNeighbor == parent)
                    continue;
                if (adj[parent].count(tmpNeighbor) == 0) {
                    return 0;
                }
            }

            if (d == parentDegree)
                ret = 2;
        }

        return ret;
    }
};