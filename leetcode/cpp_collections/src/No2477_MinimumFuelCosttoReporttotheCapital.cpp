# include <vector>
# include <queue>
using namespace std;

class Solution {
private:
    vector<bool> mask;
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {

        int N = roads.size() + 1;
        vector<vector<int>> tree(N);
        for (auto& e: roads) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        (this -> mask) = vector<bool>(N, false);

        long long count = 0;
        dfs(0, tree, count, seats);
        return count;
    }

    long long dfs(int i, const vector<vector<int>>& tree, long long& count, int& seats) {

        long long sum = 0;
        mask[i] = true;
        for (auto nei: tree[i]) {
            if (mask[nei])
                continue;
            sum += dfs(nei, tree, count, seats);
        }

        count += (sum + seats - 1) / seats;
        return sum;
    }
};