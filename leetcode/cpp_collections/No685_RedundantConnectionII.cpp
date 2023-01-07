# include <vector>
# include <numeric>
using namespace std;

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {

        vector<int> parent(1001), candiA, candiB;
        // Find node with two parents, can save them as candidates
        for (auto& i: edges) {
            if (parent[i[1]] == 0) {
                parent[i[1]] = i[0];
            } else {
                candiA = {parent[i[1]], i[1]};
                candiB = i;
                // Remove Edge 'i'
                i[1] = 0;
            }
        }

        iota(parent.begin(), parent.end(), 0);
        auto unionFind = [&](int a) {
            while (parent[a] != a)
                a = parent[a];
            return a;
        };

        // Detect Cycles
        for (auto &i: edges) {
            if (i[1] == 0)  continue;
            auto a = unionFind(i[0]);
            auto b = unionFind(i[1]);

            if (a == b) {
                if (candiA.empty())
                    return i;
                return candiA;
            }
            
            parent[i[1]] = a;
        }
            

        return candiB;
    }
};
