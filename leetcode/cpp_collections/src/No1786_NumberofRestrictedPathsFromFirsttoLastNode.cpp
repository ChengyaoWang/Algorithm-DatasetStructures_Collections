# include <queue>
# include <vector>
# include <numeric>
# include <functional>
using namespace std;

using mx = vector<vector<pair<int, int>>>;
using pq = priority_queue<
    pair<int, int>, vector<pair<int, int>>,
    function<bool (pair<int, int>, pair<int, int>)>
>; 

class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {

        mx adjMx(n);
        for (auto& e: edges) {
            adjMx[e[0] - 1].emplace_back(e[2], e[1] - 1);
            adjMx[e[1] - 1].emplace_back(e[2], e[0] - 1);
        }

        vector<int> pathCount(n, 0);
        vector<int> disToN(n, numeric_limits<int>::max());
        
        auto cmp = [](pair<int, int> a, pair<int, int> b) {
            return a.first > b.first;
        };
        pq q(cmp);

        pathCount[n - 1] = 1;
        disToN[n - 1] = 0;

        q.push(make_pair(0, n - 1));

        while (!q.empty()) {
            auto [dis, i] = q.top();
            q.pop();
            if (dis > disToN[i])    continue;
            for (auto [w, j]: adjMx[i]) {
                auto newDis = disToN[i] + w;
                if (newDis < disToN[j]) {
                    disToN[j] = newDis;
                    q.push(make_pair(newDis, j));
                }
                if (dis > disToN[j]) {
                    pathCount[i] = (
                        pathCount[i] + pathCount[j]
                    ) % 1000000007;
                }

            }
        }

        return pathCount[0];
    }
};