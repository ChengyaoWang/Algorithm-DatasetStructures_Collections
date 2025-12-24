# include <vector>
# include <algorithm>

using namespace std;

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {

        for (auto &i: tasks)
            i[0] -= i[1];

        sort(tasks.begin(), tasks.end());

        int cost = 0, remain = 0;
        for (auto &i: tasks) {
            if (remain < i[1]) {
                cost += i[1] - remain;
                remain = i[1];
            }
            remain -= i[1] + i[0];
        }

        return cost;
    }
};