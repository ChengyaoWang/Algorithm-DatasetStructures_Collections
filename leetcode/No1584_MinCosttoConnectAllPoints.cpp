# include <vector>
# include <functional>
# include <algorithm>
# include <numeric>
using namespace std;

struct Edge {
    int weight, l, r;
    Edge(int weight, int l, int r): weight(weight), l(l), r(r) {}
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        auto l1Dis = [&](int i, int j){
            return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
        };

        int n = points.size();
        vector<Edge> pq = {};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                pq.emplace_back(l1Dis(i, j), i, j);
            }
        }
        sort(pq.begin(), pq.end(), [](Edge i, Edge j){ return i.weight < j.weight; });
        
        vector<int> unionSet(n);
        iota(unionSet.begin(), unionSet.end(), 0);
        function<int(int)> findRoot = [&](int i) -> int {
            return (unionSet[i] == i) ? i: findRoot(unionSet[i]);
        };

        int totalLen = 0;
        for (auto e: pq) {
            int x = findRoot(e.l);
            int y = findRoot(e.r);

            if (x != y) {
                unionSet[x] = min(x, y);
                unionSet[y] = min(x, y);
                totalLen += e.weight;
            }
        }
        
        return totalLen;
    }
};