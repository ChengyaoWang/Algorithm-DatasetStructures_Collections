# include <vector>
# include <queue>
# include <numeric>
using namespace std;

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        // Sort And Remember index
        vector<int> idx(tasks.size());
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b){
            if (tasks[a][0] == tasks[b][0])   return tasks[a][1] < tasks[b][1];
            return tasks[a][0] < tasks[b][0];
        });

        // Create Min-Heap
        auto cmp = [&](int a, int b) {
            if (tasks[idx[a]][1] == tasks[idx[b]][1])   return idx[a] > idx[b];
            return tasks[idx[a]][1] > tasks[idx[b]][1];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

        // Start Simulation
        vector<int> res;
        long t = -1;
        for (int i = 0; i < idx.size() || !pq.empty();) {
            while (i < idx.size() && tasks[idx[i]][0] <= t) {
                pq.push(i++);
            }

            if (pq.empty()) {
                t = tasks[idx[i]][0];
            } else {
                auto tmp = pq.top(); pq.pop();
                t += tasks[idx[tmp]][1];
                res.push_back(idx[tmp]);
            }
        }
        // res.pop_back();
        return res;
    }
};