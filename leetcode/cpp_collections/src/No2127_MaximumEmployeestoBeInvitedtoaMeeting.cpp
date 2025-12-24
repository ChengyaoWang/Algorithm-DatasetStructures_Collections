# include <vector>
# include <unordered_map>
using namespace std;

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {

        int N = favorite.size();
        // We Record Nodes belonged to l2 - cycle
        vector<int> l2_group(N, -1);
        unordered_map<int, int> l2_cycle_set = {};
        vector<pair<int, int>> l2_cycle_pair = {};
        for (int i = 0; i < N; ++i) {
            if (i == favorite[favorite[i]] && l2_cycle_set.find(i) == l2_cycle_set.end()) {
                l2_cycle_set.insert_or_assign(i, 1);
                l2_cycle_set.insert_or_assign(favorite[i], 1);
                l2_cycle_pair.push_back({i, favorite[i]});
                l2_group[i] = i;
                l2_group[favorite[i]] = favorite[i];
            }
        }

        int ret = 1;
        vector<int> path = {};
        // Main body for DFS
        for (int i = 0; i < N; ++i) {
            auto p = i;
            while(l2_group[p] < 0) {
                l2_group[p] = N;
                path.push_back(p);
                p = favorite[p];
            }
            // If p is found to be one of l2_cycle group
            if (l2_cycle_set.find(l2_group[p]) != l2_cycle_set.end()) {
                auto dis = l2_group[p] != p ? l2_cycle_set[p]: 1;
                while(!path.empty()) {
                    auto elem = path.back();
                    path.pop_back();
                    l2_group[elem] = l2_group[p];
                    l2_cycle_set[elem] = ++dis;
                }
                l2_cycle_set[l2_group[i]] = max(l2_cycle_set[l2_group[i]], l2_cycle_set[i]);
            } else {
                auto l = path.size();
                while (!path.empty()) {
                    auto elem = path.back();
                    path.pop_back();
                    if (elem == p)
                        ret = max(ret, int(l - path.size()));
                }
            }
        }

        // Account for l2_cycles
        int cumSum = 0;
        for (auto& p: l2_cycle_pair) {
            cumSum += l2_cycle_set[p.first] + l2_cycle_set[p.second];
        }
        ret = max(ret, cumSum);

        return ret;        
    }
};